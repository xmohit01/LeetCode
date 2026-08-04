import pytest
from readme.generator import ReadmeGenerator
from database.database import Database

def test_generate_empty_dashboard(tmp_path):
    db = Database(tmp_path / "test.db")
    generator = ReadmeGenerator(db)
    md = generator.generate_dashboard()
    assert "No submissions yet" in md
