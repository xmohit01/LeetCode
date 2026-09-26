class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Store key-value pairs for quick lookup
        unordered_map<string, string> m;
        for(auto& p : knowledge) m[p[0]] = p[1];

        string ans = "";
        int i = 0;

        while(i < s.length()) {
            if(s[i] == '(') {
                i++;
                string key = "";

                // Extract the key inside brackets
                while(s[i] != ')') {
                    key += s[i++];
                }

                // Replace key with its value or '?' if not found
                ans += m.count(key) ? m[key] : "?";
                i++;
            }
            else{
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};