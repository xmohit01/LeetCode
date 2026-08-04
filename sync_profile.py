import os
import re
import time
import json
import logging
import datetime
import subprocess
from pathlib import Path
from typing import Dict, Any, List, Optional
import requests

from config import FOLDER_FORMAT
from utils.helpers import format_folder_name, get_extension
from database.database import Database
from database.models import SubmissionRecord, SyncState, ProblemCache

logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")
logger = logging.getLogger(__name__)

GRAPHQL_URL = "https://leetcode.com/graphql"
USERNAME = "mohitg_cse"

def fetch_public_profile(username: str = USERNAME) -> Optional[Dict[str, Any]]:
    query = """
    query getUserProfile($username: String!) {
      matchedUser(username: $username) {
        username
        githubUrl
        twitterUrl
        linkedinUrl
        profile {
          ranking
          userAvatar
          realName
          aboutMe
          school
          websites
          countryName
          company
          skillTags
          postViewCount
          reputation
          solutionCount
          categoryDiscussCount
        }
        submitStats {
          acSubmissionNum {
            difficulty
            count
            submissions
          }
          totalSubmissionNum {
            difficulty
            count
            submissions
          }
        }
        languageProblemCount {
          languageName
          problemsSolved
        }
      }
      userContestRanking(username: $username) {
        attendedContestsCount
        rating
        globalRanking
        totalParticipants
        topPercentage
        badge {
          name
        }
      }
      recentAcSubmissionList(username: $username, limit: 50) {
        id
        title
        titleSlug
        timestamp
      }
    }
    """
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
        "Content-Type": "application/json"
    }
    try:
        res = requests.post(GRAPHQL_URL, json={"query": query, "variables": {"username": username}}, headers=headers, timeout=10)
        if res.status_code == 200:
            return res.json().get("data", {})
    except Exception as e:
        logger.warning(f"Could not fetch public profile from LeetCode: {e}")
    return None

def get_git_timestamp(path_str: str) -> int:
    try:
        out = subprocess.check_output(
            ["git", "log", "-1", "--format=%ct", "--", path_str],
            text=True,
            stderr=subprocess.DEVNULL
        ).strip()
        if out.isdigit():
            return int(out)
    except Exception:
        pass
    try:
        return int(os.path.getmtime(path_str))
    except Exception:
        return int(time.time())

def parse_topics_from_readme(readme_path: Path) -> Dict[str, List[str]]:
    topic_map = {} # problem_folder -> list of topics
    if not readme_path.exists():
        return topic_map
    
    with open(readme_path, "r", encoding="utf-8", errors="ignore") as f:
        content = f.read()

    topics_section = re.split(r'<!---LeetCode Topics Start-->', content)
    if len(topics_section) > 1:
        raw_topics = topics_section[1]
        current_topic = None
        for line in raw_topics.splitlines():
            m_h2 = re.match(r'^##\s+(.+)$', line.strip())
            if m_h2:
                current_topic = m_h2.group(1).strip()
                continue
            m_link = re.search(r'\[([^\]]+)\]\(https://github\.com/[^)]+\)', line)
            if m_link and current_topic:
                folder = m_link.group(1).strip()
                if folder not in topic_map:
                    topic_map[folder] = []
                if current_topic not in topic_map[folder]:
                    topic_map[folder].append(current_topic)
    return topic_map

def map_ext_to_lang(ext: str) -> str:
    ext_map = {
        "cpp": "cpp",
        "cc": "cpp",
        "c": "c",
        "py": "python3",
        "java": "java",
        "js": "javascript",
        "ts": "typescript",
        "sql": "mysql",
        "go": "golang",
        "rs": "rust"
    }
    return ext_map.get(ext.lower().lstrip("."), "cpp")

def sync_all():
    db = Database()
    root_path = Path(".")
    solutions_dir = Path("solutions")
    solutions_dir.mkdir(exist_ok=True)
    
    logger.info("1. Fetching live public LeetCode profile...")
    profile_data = fetch_public_profile(USERNAME)
    
    recent_submissions_map = {}
    if profile_data and "recentAcSubmissionList" in profile_data:
        for sub in profile_data["recentAcSubmissionList"]:
            recent_submissions_map[sub["titleSlug"]] = sub

    logger.info("2. Parsing topic tags from master README...")
    topic_map = parse_topics_from_readme(root_path / "README.md")

    logger.info("3. Ingesting root-level LeetHub problem directories...")
    root_dirs = [d for d in root_path.iterdir() if d.is_dir() and re.match(r'^\d{4}-', d.name)]
    
    ingested_count = 0
    for folder in root_dirs:
        folder_name = folder.name
        q_id = folder_name.split("-")[0]
        slug = re.sub(r'^\d{4}-', '', folder_name)
        title = slug.replace("-", " ").title()
        difficulty = "Medium"
        tags = topic_map.get(folder_name, [])

        readme_file = folder / "README.md"
        if readme_file.exists():
            with open(readme_file, "r", encoding="utf-8", errors="ignore") as f:
                content = f.read()
                m_h2 = re.search(r'<h2><a href="https://leetcode\.com/problems/([^"/]+)/?">(.*?)</a></h2>', content)
                if m_h2:
                    slug = m_h2.group(1).strip()
                    title = re.sub(r'^\d+\.\s*', '', m_h2.group(2).strip())
                m_diff = re.search(r'<h3>(Easy|Medium|Hard)</h3>', content)
                if m_diff:
                    difficulty = m_diff.group(1).strip()

        # Check code files in root problem folder
        code_files = [f for f in folder.iterdir() if f.is_file() and f.name != "README.md"]
        lang = "cpp"
        code_content = ""
        if code_files:
            code_file = code_files[0]
            lang = map_ext_to_lang(code_file.suffix)
            try:
                with open(code_file, "r", encoding="utf-8", errors="ignore") as f:
                    code_content = f.read()
            except Exception:
                pass

        # Target folder in solutions/
        formatted_folder = format_folder_name(q_id, title, FOLDER_FORMAT)
        target_dir = solutions_dir / formatted_folder
        target_dir.mkdir(exist_ok=True)

        ext = get_extension(lang)
        target_code_path = target_dir / f"solution.{ext}"
        if code_content and not target_code_path.exists():
            with open(target_code_path, "w", encoding="utf-8") as f:
                f.write(code_content)

        target_readme = target_dir / "README.md"
        if not target_readme.exists():
            readme_text = f"# {title}\n\n"
            readme_text += f"- **Difficulty**: {difficulty}\n"
            readme_text += f"- **Language**: {lang}\n"
            readme_text += f"- **Link**: https://leetcode.com/problems/{slug}\n"
            with open(target_readme, "w", encoding="utf-8") as f:
                f.write(readme_text)

        # Determine submission timestamp
        ts = get_git_timestamp(str(folder))
        if slug in recent_submissions_map:
            try:
                ts = int(recent_submissions_map[slug]["timestamp"])
            except Exception:
                pass

        # Upsert problem cache
        db.upsert_problem_cache(ProblemCache(
            slug=slug,
            title=title,
            difficulty=difficulty,
            tags=",".join(tags),
            last_updated=time.time()
        ))

        # Create or update submission record
        sub_id = int(q_id) if q_id.isdigit() else int(hash(slug) % 100000000)
        existing = db.get_submission(sub_id)
        if not existing:
            sub_record = SubmissionRecord(
                submission_id=sub_id,
                problem_slug=slug,
                problem_title=title,
                language=lang,
                runtime="N/A",
                memory="N/A",
                timestamp=ts,
                commit_hash="local_ingest",
                state=SyncState.PUSHED
            )
            db.upsert_submission(sub_record)
            ingested_count += 1

    logger.info(f"Ingested/verified {len(root_dirs)} root folders ({ingested_count} new to DB).")

    logger.info("4. Indexing all folders in solutions/ directory...")
    all_sol_dirs = [d for d in solutions_dir.iterdir() if d.is_dir()]
    for sdir in all_sol_dirs:
        m = re.match(r'^(\d{4})_(.+)$', sdir.name)
        if not m:
            continue
        q_id = m.group(1)
        raw_name = m.group(2)
        slug = raw_name.lower().replace("_", "-")
        title = raw_name.replace("_", " ")

        cache = db.get_problem_cache(slug)
        difficulty = cache.difficulty if cache else "Medium"
        
        # Read README if difficulty is missing
        sreadme = sdir / "README.md"
        if sreadme.exists() and (not cache or cache.difficulty == "Unknown"):
            try:
                with open(sreadme, "r", encoding="utf-8", errors="ignore") as f:
                    txt = f.read()
                    m_d = re.search(r'- \*\*Difficulty\*\*:\s*(\w+)', txt)
                    if m_d:
                        difficulty = m_d.group(1).strip()
            except Exception:
                pass

        db.upsert_problem_cache(ProblemCache(
            slug=slug,
            title=title,
            difficulty=difficulty,
            tags="",
            last_updated=time.time()
        ))

        code_files = [f for f in sdir.iterdir() if f.is_file() and f.name.startswith("solution.")]
        lang = "cpp"
        if code_files:
            lang = map_ext_to_lang(code_files[0].suffix)

        sub_id = int(q_id) if q_id.isdigit() else int(abs(hash(slug)) % 100000000)
        existing = db.get_submission(sub_id)
        if not existing:
            ts = get_git_timestamp(str(sdir))
            db.upsert_submission(SubmissionRecord(
                submission_id=sub_id,
                problem_slug=slug,
                problem_title=title,
                language=lang,
                runtime="N/A",
                memory="N/A",
                timestamp=ts,
                commit_hash="local_sync",
                state=SyncState.PUSHED
            ))

    total_subs = len(db.get_all_submissions())
    logger.info(f"Total problem records in database: {total_subs}")

    # Update stats.json
    logger.info("5. Updating stats.json...")
    update_stats_json(db, profile_data)

    logger.info("Profile synchronization complete!")

def update_stats_json(db: Database, profile_data: Optional[Dict[str, Any]]):
    stats_file = Path("stats.json")
    stats_data = {}
    if stats_file.exists():
        try:
            with open(stats_file, "r", encoding="utf-8") as f:
                stats_data = json.load(f)
        except Exception:
            pass

    if "leetcode" not in stats_data:
        stats_data["leetcode"] = {}

    all_subs = db.get_all_submissions()
    unique_slugs = set(s.problem_slug for s in all_subs)

    easy_cnt = 0
    med_cnt = 0
    hard_cnt = 0

    for slug in unique_slugs:
        cache = db.get_problem_cache(slug)
        diff = cache.difficulty.lower() if cache else "medium"
        if diff == "easy":
            easy_cnt += 1
        elif diff == "hard":
            hard_cnt += 1
        else:
            med_cnt += 1

    if profile_data and "matchedUser" in profile_data:
        ac_list = profile_data["matchedUser"].get("submitStats", {}).get("acSubmissionNum", [])
        for item in ac_list:
            if item["difficulty"] == "Easy":
                easy_cnt = max(easy_cnt, item["count"])
            elif item["difficulty"] == "Medium":
                med_cnt = max(med_cnt, item["count"])
            elif item["difficulty"] == "Hard":
                hard_cnt = max(hard_cnt, item["count"])

    total_solved = easy_cnt + med_cnt + hard_cnt
    stats_data["leetcode"]["easy"] = easy_cnt
    stats_data["leetcode"]["medium"] = med_cnt
    stats_data["leetcode"]["hard"] = hard_cnt
    stats_data["leetcode"]["solved"] = total_solved

    with open(stats_file, "w", encoding="utf-8") as f:
        json.dump(stats_data, f, indent=2)
    logger.info(f"stats.json updated: Total Solved = {total_solved} (Easy: {easy_cnt}, Med: {med_cnt}, Hard: {hard_cnt})")

if __name__ == "__main__":
    sync_all()
