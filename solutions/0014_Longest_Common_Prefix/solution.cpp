class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        int len = strs[0].length();
        for(int i = 1; i < strs.size(); i++){
            string str = strs[i];
            
            int curr_len = 0;
            for(int j = 0; j < len && j < str.length(); j++){
                if(str[j] != strs[0][j]) break;
                curr_len++;
            }

            len = min(len, curr_len);
        }

        return strs[0].substr(0, len);
    }
};