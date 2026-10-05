class Solution {
public:
    int n;
    void helper(string& s, int idx, int opens, int closes, int removeOpen, int removeClose, string& temp, unordered_set<string>& result) {

        // Check whether we have processed the complete string
        if(idx == n) {
            if(opens == closes && removeOpen == 0 && removeClose == 0) {
                result.insert(temp);
            }
            return;
        }

        if(s[idx] == '(') {
            // Keep '('
            temp.push_back('(');
            helper(s, idx + 1, opens + 1, closes, removeOpen, removeClose, temp, result);
            temp.pop_back();

            // Remove '(' if it is one of the extra opening brackets
            if(removeOpen > 0) helper(s, idx + 1, opens, closes, removeOpen - 1, removeClose, temp, result);
        }
        else if(s[idx] == ')') {
            // Keep ')' only when there is a matching '('
            if(closes < opens) {
                temp.push_back(s[idx]);
                helper(s, idx + 1, opens, closes + 1, removeOpen, removeClose, temp, result);
                temp.pop_back();
            }
            
            // Remove ')' if it is one of the extra closing brackets
            if(removeClose > 0) helper(s, idx + 1, opens, closes, removeOpen, removeClose - 1, temp, result);
        }
        else {
            // Letters are always kept
            temp.push_back(s[idx]);
            helper(s, idx + 1, opens, closes, removeOpen, removeClose, temp, result);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();

        int removeOpen = 0;
        int removeClose = 0;

        // Find the minimum number of '(' and ')' that must be removed
        for(char c : s) {
            if(c == '(') {
                removeOpen++;
            }
            else if(c == ')') {
                if(removeOpen > 0) removeOpen--;

                else removeClose++;
            }
        }

        string temp;
        unordered_set<string> ans;

        helper(s, 0, 0, 0, removeOpen, removeClose, temp, ans);

        vector<string> result(ans.begin(), ans.end());
        return result;
    }
};