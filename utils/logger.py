import logging
from rich.logging import RichHandler
from config import LOGGING_LEVEL

def setup_logger():
    logging.basicConfig(
        level=LOGGING_LEVEL,
        format="%(message)s",
        datefmt="[%X]",
        handlers=[RichHandler(rich_tracebacks=True)]
    )
