import sqlite3
import os
from pathlib import Path
from typing import List, Optional
from database.models import SubmissionRecord, SyncState, ProblemCache

DB_PATH = Path(__file__).parent.parent / "state.db"

class Database:
    def __init__(self, db_path: Path = DB_PATH):
        self.db_path = db_path
        self._init_db()

    def get_connection(self):
        return sqlite3.connect(self.db_path)

    def _init_db(self):
        with self.get_connection() as conn:
            cursor = conn.cursor()
            # Submissions table
            cursor.execute('''
                CREATE TABLE IF NOT EXISTS submissions (
                    submission_id INTEGER PRIMARY KEY,
                    problem_slug TEXT NOT NULL,
                    problem_title TEXT NOT NULL,
                    language TEXT NOT NULL,
                    runtime TEXT,
                    memory TEXT,
                    timestamp INTEGER NOT NULL,
                    commit_hash TEXT,
                    state TEXT NOT NULL
                )
            ''')
            # Problem cache table
            cursor.execute('''
                CREATE TABLE IF NOT EXISTS problem_cache (
                    slug TEXT PRIMARY KEY,
                    title TEXT NOT NULL,
                    difficulty TEXT,
                    tags TEXT,
                    last_updated REAL NOT NULL
                )
            ''')
            conn.commit()

    def get_submission(self, submission_id: int) -> Optional[SubmissionRecord]:
        with self.get_connection() as conn:
            cursor = conn.cursor()
            cursor.execute("SELECT * FROM submissions WHERE submission_id = ?", (submission_id,))
            row = cursor.fetchone()
            if row:
                return SubmissionRecord(
                    submission_id=row[0],
                    problem_slug=row[1],
                    problem_title=row[2],
                    language=row[3],
                    runtime=row[4],
                    memory=row[5],
                    timestamp=row[6],
                    commit_hash=row[7],
                    state=SyncState(row[8])
                )
            return None

    def upsert_submission(self, record: SubmissionRecord):
        with self.get_connection() as conn:
            cursor = conn.cursor()
            cursor.execute('''
                INSERT INTO submissions 
                (submission_id, problem_slug, problem_title, language, runtime, memory, timestamp, commit_hash, state)
                VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
                ON CONFLICT(submission_id) DO UPDATE SET
                problem_slug=excluded.problem_slug,
                problem_title=excluded.problem_title,
                language=excluded.language,
                runtime=excluded.runtime,
                memory=excluded.memory,
                timestamp=excluded.timestamp,
                commit_hash=excluded.commit_hash,
                state=excluded.state
            ''', (
                record.submission_id, record.problem_slug, record.problem_title, 
                record.language, record.runtime, record.memory, record.timestamp, 
                record.commit_hash, record.state.value
            ))
            conn.commit()
            
    def get_submissions_by_state(self, state: SyncState) -> List[SubmissionRecord]:
        with self.get_connection() as conn:
            cursor = conn.cursor()
            cursor.execute("SELECT * FROM submissions WHERE state = ? ORDER BY timestamp ASC", (state.value,))
            rows = cursor.fetchall()
            return [
                SubmissionRecord(
                    submission_id=row[0],
                    problem_slug=row[1],
                    problem_title=row[2],
                    language=row[3],
                    runtime=row[4],
                    memory=row[5],
                    timestamp=row[6],
                    commit_hash=row[7],
                    state=SyncState(row[8])
                ) for row in rows
            ]

    def get_all_submissions(self) -> List[SubmissionRecord]:
        with self.get_connection() as conn:
            cursor = conn.cursor()
            cursor.execute("SELECT * FROM submissions ORDER BY timestamp ASC")
            rows = cursor.fetchall()
            return [
                SubmissionRecord(
                    submission_id=row[0], problem_slug=row[1], problem_title=row[2],
                    language=row[3], runtime=row[4], memory=row[5], timestamp=row[6],
                    commit_hash=row[7], state=SyncState(row[8])
                ) for row in rows
            ]

    def get_problem_cache(self, slug: str) -> Optional[ProblemCache]:
        with self.get_connection() as conn:
            cursor = conn.cursor()
            cursor.execute("SELECT * FROM problem_cache WHERE slug = ?", (slug,))
            row = cursor.fetchone()
            if row:
                return ProblemCache(
                    slug=row[0],
                    title=row[1],
                    difficulty=row[2],
                    tags=row[3],
                    last_updated=row[4]
                )
            return None

    def upsert_problem_cache(self, cache: ProblemCache):
        with self.get_connection() as conn:
            cursor = conn.cursor()
            cursor.execute('''
                INSERT INTO problem_cache (slug, title, difficulty, tags, last_updated)
                VALUES (?, ?, ?, ?, ?)
                ON CONFLICT(slug) DO UPDATE SET
                title=excluded.title,
                difficulty=excluded.difficulty,
                tags=excluded.tags,
                last_updated=excluded.last_updated
            ''', (cache.slug, cache.title, cache.difficulty, cache.tags, cache.last_updated))
            conn.commit()
