import os
import re
import datetime
import logging
from collections import Counter
from pathlib import Path
from typing import Dict, Any, List, Optional, Tuple
import requests

from database.database import Database
from database.models import SubmissionRecord, SyncState

logger = logging.getLogger(__name__)

GRAPHQL_URL = "https://leetcode.com/graphql"
DEFAULT_USERNAME = "mohitg_cse"

class ReadmeGenerator:
    def __init__(self, db: Database, username: str = DEFAULT_USERNAME):
        self.db = db
        self.username = username

    def fetch_live_stats(self) -> Optional[Dict[str, Any]]:
        query = """
        query getUserProfile($username: String!) {
          matchedUser(username: $username) {
            username
            profile {
              ranking
              userAvatar
              realName
              countryName
            }
            submitStats {
              acSubmissionNum {
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
        }
        """
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
            "Content-Type": "application/json"
        }
        try:
            res = requests.post(GRAPHQL_URL, json={"query": query, "variables": {"username": self.username}}, headers=headers, timeout=5)
            if res.status_code == 200:
                return res.json().get("data", {}).get("matchedUser")
        except Exception as e:
            logger.debug(f"Could not fetch live profile stats: {e}")
        return None

    def _get_existing_topics_section(self) -> str:
        readme_path = Path("README.md")
        if not readme_path.exists():
            return ""
        try:
            with open(readme_path, "r", encoding="utf-8", errors="ignore") as f:
                content = f.read()
            parts = re.split(r'<!---LeetCode Topics Start-->', content)
            if len(parts) > 1:
                return "<!---LeetCode Topics Start-->" + parts[1]
        except Exception:
            pass
        return ""

    def generate_dashboard(self) -> str:
        all_subs = self.db.get_all_submissions()
        submissions = [s for s in all_subs if s.state in (SyncState.DOWNLOADED, SyncState.COMMITTED, SyncState.PUSHED)]
        
        # Deduplicate submissions by problem slug (keep newest submission per problem)
        problem_map: Dict[str, SubmissionRecord] = {}
        for sub in sorted(submissions, key=lambda s: s.timestamp):
            problem_map[sub.problem_slug] = sub

        total_local_solved = len(problem_map)

        # Local difficulty counts
        diff_counter = Counter()
        for slug in problem_map.keys():
            cache = self.db.get_problem_cache(slug)
            diff = cache.difficulty if cache and cache.difficulty else "Medium"
            diff_counter[diff] += 1

        easy_count = diff_counter.get("Easy", 0)
        med_count = diff_counter.get("Medium", 0)
        hard_count = diff_counter.get("Hard", 0)

        # Local language counts
        lang_counter = Counter()
        for sub in problem_map.values():
            lang = sub.language.lower()
            if lang in ("cpp", "c++"):
                lang_counter["C++"] += 1
            elif lang in ("js", "javascript"):
                lang_counter["JavaScript"] += 1
            elif lang in ("py", "python", "python3"):
                lang_counter["Python"] += 1
            elif lang in ("sql", "mysql"):
                lang_counter["MySQL"] += 1
            else:
                lang_counter[lang.title()] += 1

        # Fetch live stats for extra precision
        live_stats = self.fetch_live_stats()
        ranking_str = "Top 10%"
        if live_stats:
            ranking = live_stats.get("profile", {}).get("ranking")
            if ranking:
                ranking_str = f"#{ranking:,}"
            ac_list = live_stats.get("submitStats", {}).get("acSubmissionNum", [])
            for item in ac_list:
                if item["difficulty"] == "All":
                    total_local_solved = max(total_local_solved, item["count"])
                elif item["difficulty"] == "Easy":
                    easy_count = max(easy_count, item["count"])
                elif item["difficulty"] == "Medium":
                    med_count = max(med_count, item["count"])
                elif item["difficulty"] == "Hard":
                    hard_count = max(hard_count, item["count"])
            
            for lang_item in live_stats.get("languageProblemCount", []):
                lname = lang_item.get("languageName")
                lcnt = lang_item.get("problemsSolved", 0)
                if lname:
                    lang_counter[lname] = max(lang_counter[lname], lcnt)

        # Map solutions directory for solution links
        solutions_dir = Path("solutions")
        sol_folder_map = {}
        if solutions_dir.exists():
            for folder in solutions_dir.iterdir():
                if folder.is_dir():
                    # extract slug
                    m = re.match(r'^\d{4}_(.+)$', folder.name)
                    if m:
                        clean_slug = m.group(1).lower().replace('_', '-')
                        sol_folder_map[clean_slug] = folder.name
                    # also map full lowercase
                    sol_folder_map[folder.name.lower()] = folder.name

        now_str = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        # Build Markdown
        md = "# ⚡ LeetCode Problem Solutions & Dashboard\n\n"
        
        md += '<p align="center">\n'
        md += f'  <a href="https://leetcode.com/u/{self.username}/">\n'
        md += f'    <img src="https://img.shields.io/badge/LeetCode-{self.username}-FFA116?style=for-the-badge&logo=leetcode&logoColor=black" alt="LeetCode Profile" />\n'
        md += '  </a>\n'
        md += '  <a href="https://github.com/xmohit01">\n'
        md += '    <img src="https://img.shields.io/badge/GitHub-xmohit01-181717?style=for-the-badge&logo=github&logoColor=white" alt="GitHub Profile" />\n'
        md += '  </a>\n'
        md += f'  <img src="https://img.shields.io/badge/Total%20Solved-{total_local_solved}-brightgreen?style=for-the-badge" alt="Solved" />\n'
        md += f'  <img src="https://img.shields.io/badge/Global%20Rank-{ranking_str}-4B8BBE?style=for-the-badge" alt="Rank" />\n'
        md += '</p>\n\n'

        md += '<p align="center">\n'
        md += f'  <a href="https://leetcode.com/u/{self.username}/">\n'
        md += f'    <img src="https://leetcard.jacoblin.cool/{self.username}?theme=nord&font=Karma&ext=heatmap" alt="LeetCode Stats Card" />\n'
        md += '  </a>\n'
        md += '</p>\n\n'

        md += "## 📊 Profile Overview\n\n"
        md += "| Metric | Statistics |\n"
        md += "| :--- | :--- |\n"
        md += f"| **LeetCode Profile** | [@{self.username}](https://leetcode.com/u/{self.username}/) 🇮🇳 |\n"
        md += f"| **Total Problems Solved** | **{total_local_solved}** Problems |\n"
        md += f"| **Difficulty Breakdown** | 🟢 **Easy:** {easy_count} &nbsp;\\|&nbsp; 🟡 **Medium:** {med_count} &nbsp;\\|&nbsp; 🔴 **Hard:** {hard_count} |\n"
        
        # Format language badges
        lang_badges = []
        for lang_name, count in sorted(lang_counter.items(), key=lambda x: x[1], reverse=True):
            if count > 0:
                if lang_name == "C++":
                    lang_badges.append(f"![C++](https://img.shields.io/badge/C++-{count}-00599C?style=flat-square&logo=c%2B%2B)")
                elif lang_name == "JavaScript":
                    lang_badges.append(f"![JavaScript](https://img.shields.io/badge/JavaScript-{count}-F7DF1E?style=flat-square&logo=javascript&logoColor=black)")
                elif lang_name == "MySQL":
                    lang_badges.append(f"![MySQL](https://img.shields.io/badge/MySQL-{count}-4479A1?style=flat-square&logo=mysql&logoColor=white)")
                elif lang_name == "Python":
                    lang_badges.append(f"![Python](https://img.shields.io/badge/Python-{count}-3776AB?style=flat-square&logo=python&logoColor=white)")
                else:
                    lang_badges.append(f"`{lang_name}: {count}`")

        md += f"| **Languages** | {' '.join(lang_badges)} |\n"
        md += "| **Sync Engine** | Automated via LeetHub & Antigravity Pipeline |\n"
        md += f"| **Last Synchronized** | `{now_str}` |\n\n"

        md += "## 📚 Problem Solutions Index\n\n"
        md += "| # | Problem | Difficulty | Language | Solution | Solved Date |\n"
        md += "|:---:|:---|:---:|:---:|:---:|:---:|\n"

        # Sort problems by timestamp descending (newest first)
        sorted_records = sorted(problem_map.values(), key=lambda s: s.timestamp, reverse=True)

        for idx, sub in enumerate(sorted_records, start=1):
            cache = self.db.get_problem_cache(sub.problem_slug)
            diff = cache.difficulty if cache and cache.difficulty else "Medium"
            if diff.lower() == "easy":
                diff_badge = "🟢 Easy"
            elif diff.lower() == "hard":
                diff_badge = "🔴 Hard"
            else:
                diff_badge = "🟡 Medium"

            date_str = datetime.datetime.fromtimestamp(sub.timestamp).strftime("%Y-%m-%d")
            
            # Find solution link
            sol_folder = sol_folder_map.get(sub.problem_slug)
            if sol_folder:
                sol_link = f"[Code](./solutions/{sol_folder})"
            else:
                # check if root folder exists
                q_id_padded = f"{sub.submission_id:04d}" if sub.submission_id < 10000 else ""
                root_match = [d for d in Path(".").iterdir() if d.is_dir() and sub.problem_slug in d.name]
                if root_match:
                    sol_link = f"[Code](./{root_match[0].name})"
                else:
                    sol_link = "📝 Solution"

            lang_label = sub.language.upper()
            if lang_label == "CPP":
                lang_label = "C++"

            md += f"| {idx} | [{sub.problem_title}](https://leetcode.com/problems/{sub.problem_slug}) | {diff_badge} | `{lang_label}` | {sol_link} | {date_str} |\n"

        md += "\n"

        # Append existing topics section if available
        topics_sec = self._get_existing_topics_section()
        if topics_sec:
            md += topics_sec + "\n"

        return md

    def write_readme(self):
        content = self.generate_dashboard()
        with open("README.md", "w", encoding="utf-8") as f:
            f.write(content)
        logger.info("README dashboard generated successfully.")
