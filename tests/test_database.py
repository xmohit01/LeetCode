import pytest
from database.database import Database
from database.models import SubmissionRecord, SyncState

def test_database_init(tmp_path):
    db = Database(tmp_path / "test.db")
    assert db is not None

def test_upsert_submission(tmp_path):
    db = Database(tmp_path / "test.db")
    rec = SubmissionRecord(1, "two-sum", "Two Sum", "python", "10ms", "10mb", 100000, None, SyncState.FETCHED)
    db.upsert_submission(rec)
    fetched = db.get_submission(1)
    assert fetched.problem_slug == "two-sum"
