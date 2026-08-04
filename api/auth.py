import os
from config import LEETCODE_SESSION, CSRFTOKEN

def get_auth_headers() -> dict:
    return {
        "Content-Type": "application/json",
        "Referer": "https://leetcode.com/",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36",
        "x-csrftoken": CSRFTOKEN or ""
    }

def get_auth_cookies() -> dict:
    return {
        "LEETCODE_SESSION": LEETCODE_SESSION or "",
        "csrftoken": CSRFTOKEN or ""
    }
