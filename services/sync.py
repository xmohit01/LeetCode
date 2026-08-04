import logging
from typing import Optional
from database.database import Database
from database.models import SyncState
from repo.provider import RepositoryProvider

logger = logging.getLogger(__name__)

class SyncService:
    def __init__(self, db: Database, repo: RepositoryProvider):
        self.db = db
        self.repo = repo

    def commit_and_push_all(self):
        to_commit = self.db.get_submissions_by_state(SyncState.DOWNLOADED)
        if not to_commit:
            logger.info("No new downloaded submissions to commit.")
            return

        logger.info(f"Adding {len(to_commit)} submissions to Git.")
        
        self.repo.add_files(["solutions", "README.md"])
        
        if len(to_commit) == 1:
            msg = f"Added {to_commit[0].problem_title} solution"
        else:
            msg = f"Added {len(to_commit)} new LeetCode solutions"
        
        commit_hash = self.repo.commit(msg)
        
        if commit_hash:
            logger.info(f"Committed changes: {commit_hash}")
            for sub in to_commit:
                sub.commit_hash = commit_hash
                sub.state = SyncState.COMMITTED
                self.db.upsert_submission(sub)
        
        logger.info("Pushing to remote...")
        self.repo.push()
        
        for sub in to_commit:
            sub.state = SyncState.PUSHED
            self.db.upsert_submission(sub)
            
        logger.info("Sync completed successfully.")
