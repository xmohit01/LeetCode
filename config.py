import os
import yaml
from pathlib import Path
from dotenv import load_dotenv

load_dotenv()

def load_config() -> dict:
    config_path = Path(__file__).parent / "config.yaml"
    if not config_path.exists():
        raise FileNotFoundError(f"Missing configuration file at {config_path}")
    
    with open(config_path, "r", encoding="utf-8") as f:
        return yaml.safe_load(f)

# Global variables loaded once
CONFIG = load_config()

# Secrets
LEETCODE_SESSION = os.getenv("LEETCODE_SESSION")
CSRFTOKEN = os.getenv("CSRFTOKEN")

# App settings
FOLDER_FORMAT = CONFIG.get("app", {}).get("folder_format", "underscore")
DEFAULT_LANGUAGE = CONFIG.get("app", {}).get("default_language", "cpp")

# Download settings
WORKERS = CONFIG.get("download", {}).get("workers", 4)
MAX_RETRIES = CONFIG.get("download", {}).get("max_retries", 5)
RETRY_BASE_BACKOFF = CONFIG.get("download", {}).get("retry_base_backoff", 1.0)

# Git settings
AUTO_PUSH = CONFIG.get("git", {}).get("auto_push", True)
REPOSITORY_PATH = CONFIG.get("git", {}).get("repository_path", ".")
BRANCH = CONFIG.get("git", {}).get("branch", "main")

# Logging settings
LOGGING_LEVEL = CONFIG.get("logging", {}).get("level", "INFO")
