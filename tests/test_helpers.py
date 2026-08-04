from utils.helpers import format_folder_name, get_extension

def test_format_folder_name():
    assert format_folder_name("1", "Two Sum", "underscore") == "0001_Two_Sum"
    assert format_folder_name("1", "Two Sum", "dot") == "0001. Two Sum"
    assert format_folder_name("1234", "A-B C", "underscore") == "1234_AB_C"

def test_get_extension():
    assert get_extension("python") == "py"
    assert get_extension("cpp") == "cpp"
    assert get_extension("unknown") == "txt"
