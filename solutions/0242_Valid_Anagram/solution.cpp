class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        bool ans = true;
        int n = s.length() - 1;
        while(n >= 0){
            if(s[n] != t[n]){
                ans = false;
                break;
            }
            n--;
        }
        return ans;
    }
};