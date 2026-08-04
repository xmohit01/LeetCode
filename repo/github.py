import os
from typing import List
from git import Repo
import logging
from git.exc import GitCommandError
from repo.provider import RepositoryProvider
from config import REPOSITORY_PATH, BRANCH

logger = logging.getLogger(__name__)

class GitHubProvider(RepositoryProvider):
    def __init__(self, repo_path: str = REPOSITORY_PATH):
        self.repo_path = repo_path
        try:
            self.repo = Repo(self.repo_path)
            if self.repo.bare:
                raise Exception("Repository is bare.")
        except Exception as e:
            logger.error(f"Failed to initialize Git repository at {self.repo_path}: {e}")
            raise

    def add_files(self, paths: List[str]):
        try:
            for p in paths:
                self.repo.git.add(p)
        except GitCommandError as e:
            logger.error(f"Error adding files: {e}")
            raise

    def commit(self, message: str) -> str:
        try:
            if not self.repo.is_dirty(untracked_files=True):
                return ""
            self.repo.git.commit("-m", message)
            return self.repo.head.commit.hexsha
        except GitCommandError as e:
            logger.error(f"Error committing: {e}")
            raise

    def push(self):
        try:
            origin = self.repo.remote(name='origin')
            origin.push(BRANCH)
            logger.info("Successfully pushed to GitHub.")
        except Exception as e:
            logger.error(f"Error pushing to GitHub: {e}")
            raise

    def pull(self):
        try:
            origin = self.repo.remote(name='origin')
            origin.pull(BRANCH)
            logger.info("Successfully pulled from GitHub.")
        except Exception as e:
            logger.error(f"Error pulling from GitHub: {e}")
            raise
