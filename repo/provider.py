from abc import ABC, abstractmethod
from typing import List

class RepositoryProvider(ABC):
    @abstractmethod
    def add_files(self, paths: List[str]):
        pass

    @abstractmethod
    def commit(self, message: str) -> str:
        pass

    @abstractmethod
    def push(self):
        pass

    @abstractmethod
    def pull(self):
        pass
