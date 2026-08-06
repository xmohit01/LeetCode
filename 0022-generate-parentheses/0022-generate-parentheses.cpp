class Solution {
public:
    void helper(int n, string& temp, vector<string>& ans, int openBracks, int closeBracks){
        if(temp.length() == 2 * n){
            ans.push_back(temp);
            return;
        }

        if(openBracks < n){
            temp += '(';

            helper(n, temp, ans, openBracks + 1, closeBracks);
            temp.pop_back();
        }
        if(closeBracks < openBracks){
            temp += ')';

            helper(n, temp, ans, openBracks, closeBracks + 1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";

        helper(n, temp, ans, 0, 0);
        return ans;
    }
};