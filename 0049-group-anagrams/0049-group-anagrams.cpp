class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(string& str : strs){
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            m[sortedStr].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto& p : m){
            ans.push_back(p.second);
        }

        return ans;
    }
};