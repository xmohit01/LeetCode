class Solution {
public:
    bool isPalimdrome(string& s, int i, int j) {
        while(i <= j) {
            if(s[i++] != s[j--]) return false;
        }

        return true;
    }
    string longestPalindrome(string s) {
        int n = s.length();

        int len = 0;
        string ans;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                if(isPalimdrome(s, i, j)) {
                    if(j - i + 1 > len) {
                        len = j - i + 1;

                        ans = s.substr(i, len);
                    }
                }
            }
        }

        return ans;
    }
};