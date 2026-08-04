import time
import random
import logging
from typing import Dict, Any, Optional
import requests

from config import MAX_RETRIES, RETRY_BASE_BACKOFF
from api.auth import get_auth_headers, get_auth_cookies
from api.graphql import SUBMISSION_DETAILS_QUERY

logger = logging.getLogger(__name__)

class LeetCodeClient:
    def __init__(self):
        self.session = requests.Session()
        self.session.headers.update(get_auth_headers())
        self.session.cookies.update(get_auth_cookies())
        self.graphql_url = "https://leetcode.com/graphql"
        self.api_url = "https://leetcode.com/api"

    def _request_with_retry(self, method: str, url: str, **kwargs) -> requests.Response:
        retries = 0
        while retries <= MAX_RETRIES:
            try:
                response = self.session.request(method, url, **kwargs)
                if response.status_code == 200:
                    return response
                
                # Check for Authentication errors (401/403) - do not retry
                if response.status_code in (401, 403):
                    logger.error(f"Authentication error {response.status_code} on {url}. Session cookie may be expired.")
                    response.raise_for_status()

                # Check if error is transient (429 Too Many Requests, or 5xx Server Errors)
                if response.status_code == 429 or 500 <= response.status_code < 600:
                    retries += 1
                    if retries > MAX_RETRIES:
                        response.raise_for_status()
                    
                    sleep_time = (RETRY_BASE_BACKOFF * (2 ** (retries - 1))) + random.uniform(0, 1)
                    logger.warning(f"Transient error {response.status_code} on {url}. Retrying in {sleep_time:.2f}s (Attempt {retries}/{MAX_RETRIES})")
                    time.sleep(sleep_time)
                else:
                    response.raise_for_status()
            except requests.exceptions.HTTPError as e:
                # If HTTP error is 401/403, raise immediately
                if e.response is not None and e.response.status_code in (401, 403):
                    raise e
                retries += 1
                if retries > MAX_RETRIES:
                    raise e
                sleep_time = (RETRY_BASE_BACKOFF * (2 ** (retries - 1))) + random.uniform(0, 1)
                logger.warning(f"HTTP error {e} on {url}. Retrying in {sleep_time:.2f}s (Attempt {retries}/{MAX_RETRIES})")
                time.sleep(sleep_time)
            except requests.exceptions.RequestException as e:
                retries += 1
                if retries > MAX_RETRIES:
                    raise e
                sleep_time = (RETRY_BASE_BACKOFF * (2 ** (retries - 1))) + random.uniform(0, 1)
                logger.warning(f"Network error {e} on {url}. Retrying in {sleep_time:.2f}s (Attempt {retries}/{MAX_RETRIES})")
                time.sleep(sleep_time)
        
        raise Exception(f"Max retries exceeded for {url}")

    def fetch_submissions(self, offset: int = 0, limit: int = 20) -> Dict[str, Any]:
        """
        Fetches submissions using the REST API which correctly provides full history.
        """
        url = f"{self.api_url}/submissions/?offset={offset}&limit={limit}"
        response = self._request_with_retry("GET", url)
        return response.json()

    def fetch_submission_details(self, submission_id: int) -> Dict[str, Any]:
        """
        Fetches detailed information for a specific submission including code and metrics.
        """
        payload = {
            "query": SUBMISSION_DETAILS_QUERY,
            "variables": {"submissionId": submission_id},
            "operationName": "submissionDetails"
        }
        response = self._request_with_retry("POST", self.graphql_url, json=payload)
        data = response.json()
        if "errors" in data:
            raise Exception(f"GraphQL Error: {data['errors']}")
        return data.get("data", {}).get("submissionDetails", {})

    def fetch_public_profile(self, username: str = "mohitg_cse") -> Optional[Dict[str, Any]]:
        """
        Fetches public profile data via GraphQL without requiring active private session cookies.
        """
        query = """
        query getUserProfile($username: String!) {
          matchedUser(username: $username) {
            username
            profile {
              ranking
              userAvatar
              realName
              countryName
            }
            submitStats {
              acSubmissionNum {
                difficulty
                count
                submissions
              }
            }
            languageProblemCount {
              languageName
              problemsSolved
            }
          }
          recentAcSubmissionList(username: $username, limit: 50) {
            id
            title
            titleSlug
            timestamp
          }
        }
        """
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
            "Content-Type": "application/json"
        }
        try:
            res = requests.post(self.graphql_url, json={"query": query, "variables": {"username": username}}, headers=headers, timeout=10)
            if res.status_code == 200:
                return res.json().get("data", {})
        except Exception as e:
            logger.warning(f"Error fetching public profile: {e}")
        return None
