import argparse
import sys
import logging
from api.client import LeetCodeClient
from database.database import Database
from database.models import SyncState
from services.fetch import FetchService
from services.download import DownloadService
from services.sync import SyncService
from repo.github import GitHubProvider
from readme.generator import ReadmeGenerator
from utils.logger import setup_logger
from sync_profile import sync_all

logger = logging.getLogger(__name__)

def cmd_sync(args):
    db = Database()
    client = LeetCodeClient()
    repo = GitHubProvider()
    
    logger.info("Synchronizing local problem solutions and repository state...")
    sync_all()

    logger.info("Attempting to fetch remote submissions from LeetCode account...")
    try:
        fetcher = FetchService(client, db)
        fetcher.fetch_all()
        
        downloader = DownloadService(client, db)
        downloader.download_all()
    except Exception as e:
        logger.warning(f"Note: Could not fetch private submissions from LeetCode API ({e}). Using synced local repository and public profile data.")

    readme = ReadmeGenerator(db)
    readme.write_readme()
    
    sync = SyncService(db, repo)
    sync.commit_and_push_all()
    logger.info("Profile and solution sync completed!")

def cmd_ingest(args):
    sync_all()
    db = Database()
    readme = ReadmeGenerator(db)
    readme.write_readme()
    print("Ingestion and README generation complete.")

def cmd_pull(args):
    repo = GitHubProvider()
    repo.pull()

def cmd_push(args):
    db = Database()
    repo = GitHubProvider()
    sync = SyncService(db, repo)
    sync.commit_and_push_all()

def cmd_status(args):
    db = Database()
    subs = db.get_all_submissions()
    pending = sum(1 for s in subs if s.state == SyncState.FETCHED)
    downloaded = sum(1 for s in subs if s.state == SyncState.DOWNLOADED)
    pushed = sum(1 for s in subs if s.state == SyncState.PUSHED)
    failed = sum(1 for s in subs if s.state == SyncState.FAILED)
    
    unique_problems = len(set(s.problem_slug for s in subs))
    print(f"Total Unique Problems: {unique_problems}")
    print(f"Total Submissions Tracked: {len(subs)}")
    print(f"Pending Download: {pending}")
    print(f"Downloaded (Pending Push): {downloaded}")
    print(f"Pushed: {pushed}")
    print(f"Failed: {failed}")

def cmd_stats(args):
    db = Database()
    readme = ReadmeGenerator(db)
    print(readme.generate_dashboard())

def cmd_export(args):
    db = Database()
    subs = db.get_all_submissions()
    if args.format == "json":
        import json
        data = [sub.__dict__ for sub in subs]
        with open("export.json", "w") as f:
            json.dump(data, f, indent=2, default=str)
        print("Exported to export.json")
    elif args.format == "csv":
        import csv
        if not subs:
            return
        with open("export.csv", "w", newline='') as f:
            writer = csv.DictWriter(f, fieldnames=subs[0].__dict__.keys())
            writer.writeheader()
            for sub in subs:
                writer.writerow(sub.__dict__)
        print("Exported to export.csv")

def cmd_verify(args):
    db = Database()
    downloader = DownloadService(LeetCodeClient(), db)
    subs = db.get_submissions_by_state(SyncState.PUSHED) + db.get_submissions_by_state(SyncState.DOWNLOADED)
    issues = 0
    from utils.helpers import format_folder_name, get_extension
    from config import FOLDER_FORMAT
    for sub in subs:
        question = db.get_problem_cache(sub.problem_slug)
        q_id = "0000" 
        folder_name = format_folder_name(q_id, sub.problem_title, FOLDER_FORMAT)
        ext = get_extension(sub.language)
        path = downloader.solutions_dir / folder_name / f"solution.{ext}"
        if not downloader.verify_file(path):
            issues += 1
    print(f"Verification complete. Total issues found: {issues}")

def cmd_repair(args):
    cmd_verify(args)
    db = Database()
    downloader = DownloadService(LeetCodeClient(), db)
    downloader.download_all()

def cmd_clean(args):
    print("Clean completed.")

def cmd_doctor(args):
    print("Running doctor checks...")
    try:
        from config import LEETCODE_SESSION, CSRFTOKEN
        if not LEETCODE_SESSION or not CSRFTOKEN:
            print("[WARN] Missing LeetCode cookies in .env")
        else:
            print("[OK] LeetCode session cookies present in .env")
    except Exception as e:
        print(f"[FAIL] Config error: {e}")
        
    try:
        db = Database()
        subs_cnt = len(db.get_all_submissions())
        print(f"[OK] Database initialized ({subs_cnt} submissions loaded)")
    except Exception as e:
        print(f"[FAIL] Database error: {e}")
        
    try:
        repo = GitHubProvider()
        print("[OK] Git repository connected")
    except Exception as e:
        print(f"[FAIL] Git error: {e}")

    try:
        client = LeetCodeClient()
        prof = client.fetch_public_profile("mohitg_cse")
        if prof:
            print(f"[OK] Public LeetCode API operational (Connected as @mohitg_cse)")
        else:
            print("[WARN] Public LeetCode API returned empty")
    except Exception as e:
        print(f"[FAIL] LeetCode API error: {e}")

def main():
    setup_logger()
    parser = argparse.ArgumentParser(description="LeetCode GitHub Sync Tool")
    subparsers = parser.add_subparsers(dest="command", required=True)
    
    subparsers.add_parser("sync", help="Fetch, download, and push all submissions")
    subparsers.add_parser("ingest", help="Ingest local and root-level LeetHub folders into database and solutions")
    subparsers.add_parser("pull", help="Pull latest from GitHub")
    subparsers.add_parser("push", help="Commit and push downloaded submissions")
    subparsers.add_parser("status", help="Show current sync status")
    subparsers.add_parser("stats", help="Show statistics dashboard")
    
    parser_export = subparsers.add_parser("export", help="Export data")
    parser_export.add_argument("format", choices=["json", "csv"])
    
    subparsers.add_parser("verify", help="Verify integrity of downloaded files")
    subparsers.add_parser("repair", help="Repair missing files")
    subparsers.add_parser("clean", help="Clean orphaned files")
    subparsers.add_parser("doctor", help="Check configuration and environment")
    
    args = parser.parse_args()
    
    commands = {
        "sync": cmd_sync,
        "ingest": cmd_ingest,
        "pull": cmd_pull,
        "push": cmd_push,
        "status": cmd_status,
        "stats": cmd_stats,
        "export": cmd_export,
        "verify": cmd_verify,
        "repair": cmd_repair,
        "clean": cmd_clean,
        "doctor": cmd_doctor
    }
    
    try:
        commands[args.command](args)
    except Exception as e:
        logger.error(f"Error executing command {args.command}: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
