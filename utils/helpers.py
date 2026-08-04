import re

EXTENSION_MAP = {
    "cpp": "cpp",
    "java": "java",
    "python": "py",
    "python3": "py",
    "c": "c",
    "csharp": "cs",
    "javascript": "js",
    "typescript": "ts",
    "php": "php",
    "swift": "swift",
    "kotlin": "kt",
    "dart": "dart",
    "golang": "go",
    "ruby": "rb",
    "scala": "scala",
    "rust": "rs",
    "racket": "rkt",
    "erlang": "erl",
    "elixir": "ex",
}

def get_extension(lang: str) -> str:
    return EXTENSION_MAP.get(lang.lower(), "txt")

def format_folder_name(problem_id: str, title: str, folder_format: str) -> str:
    try:
        pid = f"{int(problem_id):04d}"
    except:
        pid = problem_id

    clean_title = re.sub(r'[^\w\s\-]', '', title).strip()

    if folder_format == "underscore":
        clean_title = re.sub(r'[\s\-]+', '_', clean_title)
        return f"{pid}_{clean_title}"
    else:
        clean_title = re.sub(r'\s+', ' ', clean_title)
        return f"{pid}. {clean_title}"
