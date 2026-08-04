import os
import logging
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
from typing import List

from api.client import LeetCodeClient
from database.database import Database
from database.models import SubmissionRecord, SyncState, ProblemCache
from config import WORKERS, FOLDER_FORMAT
from utils.helpers import format_folder_name, get_extension

logger = logging.getLogger(__name__)

class DownloadService:
    def __init__(self, client: LeetCodeClient, db: Database):
        self.client = client
        self.db = db
        self.solutions_dir = Path("solutions")
        self.solutions_dir.mkdir(exist_ok=True)

    def verify_file(self, file_path: Path) -> bool:
        if not file_path.exists():
            return False
        if file_path.stat().st_size == 0:
            return False
        return True

    def process_submission(self, sub: SubmissionRecord):
        try:
            details = None
            for attempt in range(3):
                details = self.client.fetch_submission_details(sub.submission_id)
                if details:
                    break
                logger.warning(f"Submission {sub.submission_id} returned empty details (hidden rate limit). Retrying... ({attempt+1}/3)")
                time.sleep(2 + attempt * 2)
                
            if not details:
                raise Exception(f"No details returned for submission {sub.submission_id} after retries")
                
            code = details.get("code")
            if not code:
                raise Exception(f"No code found for submission {sub.submission_id}")

            question = details.get("question") or {}
            q_id = question.get("questionId", "0000")
            difficulty = question.get("difficulty", "Unknown")
            
            self.db.upsert_problem_cache(ProblemCache(
                slug=sub.problem_slug,
                title=sub.problem_title,
                difficulty=difficulty,
                tags="",
                last_updated=time.time()
            ))

            folder_name = format_folder_name(q_id, sub.problem_title, FOLDER_FORMAT)
            problem_dir = self.solutions_dir / folder_name
            problem_dir.mkdir(exist_ok=True)

            ext = get_extension(sub.language)
            file_name = f"solution.{ext}"
            file_path = problem_dir / file_name
            
            with open(file_path, "w", encoding="utf-8") as f:
                f.write(code)

            if not self.verify_file(file_path):
                raise Exception("File verification failed (empty or missing).")

            readme_path = problem_dir / "README.md"
            readme_content = f"# {sub.problem_title}\n\n"
            readme_content += f"- **Difficulty**: {difficulty}\n"
            readme_content += f"- **Language**: {sub.language}\n"
            readme_content += f"- **Runtime**: {sub.runtime}\n"
            readme_content += f"- **Memory**: {sub.memory}\n"
            readme_content += f"- **Link**: https://leetcode.com/problems/{sub.problem_slug}\n"
            
            with open(readme_path, "w", encoding="utf-8") as f:
                f.write(readme_content)

            sub.state = SyncState.DOWNLOADED
            self.db.upsert_submission(sub)
            return True
        except Exception as e:
            logger.error(f"Failed to download submission {sub.submission_id}: {e}")
            sub.state = SyncState.FAILED
            self.db.upsert_submission(sub)
            return False

    def download_all(self):
        pending = self.db.get_submissions_by_state(SyncState.FETCHED)
        failed = self.db.get_submissions_by_state(SyncState.FAILED)
        to_download = pending + failed
        
        if not to_download:
            logger.info("No new submissions to download.")
            return

        logger.info(f"Starting download of {len(to_download)} submissions with {WORKERS} workers.")
        
        success_count = 0
        with ThreadPoolExecutor(max_workers=WORKERS) as executor:
            future_to_sub = {executor.submit(self.process_submission, sub): sub for sub in to_download}
            for future in as_completed(future_to_sub):
                if future.result():
                    success_count += 1
        
        logger.info(f"Downloaded {success_count}/{len(to_download)} successfully.")
