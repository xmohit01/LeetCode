import logging
from api.client import LeetCodeClient
from database.database import Database
from database.models import SubmissionRecord, SyncState

logger = logging.getLogger(__name__)

class FetchService:
    def __init__(self, client: LeetCodeClient, db: Database):
        self.client = client
        self.db = db

    def fetch_all(self):
        offset = 0
        limit = 20
        has_next = True
        
        logger.info("Fetching submissions from LeetCode...")
        
        while has_next:
            data = self.client.fetch_submissions(offset=offset, limit=limit)
            submissions = data.get("submissions_dump", [])
            has_next = data.get("has_next", False)
            
            if not submissions:
                break
                
            for sub in submissions:
                if sub.get("status_display") == "Accepted":
                    sub_id = sub.get("id")
                    existing = self.db.get_submission(sub_id)
                    
                    if existing and existing.state not in [SyncState.FAILED, SyncState.PENDING]:
                        continue 
                    
                    record = SubmissionRecord(
                        submission_id=sub_id,
                        problem_slug=sub.get("title_slug"),
                        problem_title=sub.get("title"),
                        language=sub.get("lang"),
                        runtime=sub.get("runtime"),
                        memory=sub.get("memory"),
                        timestamp=sub.get("timestamp"),
                        commit_hash=None,
                        state=SyncState.FETCHED
                    )
                    self.db.upsert_submission(record)
                    
            logger.info(f"Fetched {offset + len(submissions)} submissions...")
            offset += limit
