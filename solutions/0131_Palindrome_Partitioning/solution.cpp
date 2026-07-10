class Solution {
public:

    bool isPalindrome(string s){
        int st = 0, end = s.size() - 1;
        while(st <= end){
            if(s[st] != s[end]){
                return false;
            }
            st++; end--;
        }
        return true;
    }

    void helper(string s, vector<string> &parts, vector<vector<string>> &ans){
        int n = s.size();
        if(n == 0){
            ans.push_back(parts);
            return;
        }


        for(int i = 0; i < n; i++){
            string part = s.substr(0, i + 1);

            if(isPalindrome(part)){
                parts.push_back(part);

                helper(s.substr(i + 1), parts, ans);

                parts.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;

        helper(s, parts, ans);

        return ans;
    }
};