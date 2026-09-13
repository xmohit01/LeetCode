class Solution {
public:
    int n;
    void helper(vector<string>& values, vector<string>& ans, string temp, int idx){
        if(idx == n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < values[idx].size(); i++){
            temp += values[idx][i];
            helper(values, ans, temp, idx + 1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        vector<string> values;
        for(int d : digits){
            if(d == '2') values.push_back("abc");
            else if(d == '3') values.push_back("def");
            else if(d == '4') values.push_back("ghi");
            else if(d == '5') values.push_back("jkl");
            else if(d == '6') values.push_back("mno");
            else if(d == '7') values.push_back("pqrs");
            else if(d == '8') values.push_back("tuv");
            else if(d == '9') values.push_back("wxyz");
        }

        n = values.size();
        string temp = "";
        helper(values, ans, temp, 0);
        return ans;
    }
};