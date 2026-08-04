from dataclasses import dataclass
from typing import Optional
from enum import Enum

class SyncState(str, Enum):
    PENDING = "PENDING"
    FETCHED = "FETCHED"
    DOWNLOADED = "DOWNLOADED"
    COMMITTED = "COMMITTED"
    PUSHED = "PUSHED"
    FAILED = "FAILED"

@dataclass
class ProblemCache:
    slug: str
    title: str
    difficulty: str
    tags: str
    last_updated: float

@dataclass
class SubmissionRecord:
    submission_id: int
    problem_slug: str
    problem_title: str
    language: str
    runtime: str
    memory: str
    timestamp: int
    commit_hash: Optional[str]
    state: SyncState
