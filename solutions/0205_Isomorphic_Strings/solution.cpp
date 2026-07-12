class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        unordered_map<char, char> m;

        for(int i = 0; i < n; i++){
            if(m.count(s[i])){
                if(m[s[i]] != t[i]) return false;
            }
            else m[s[i]] = t[i];
        }
        m.clear();
        for(int i = 0; i < n; i++){
            if(m.count(t[i])){
                if(m[t[i]] != s[i]) return false;
            }
            else m[t[i]] = s[i];
        }

        return true;
    }
};