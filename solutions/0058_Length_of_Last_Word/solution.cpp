class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = s.size() - 1;
        int ans = s.size() - 1;
        while(count >= 0 && s[count] == ' ') count--;
        while(count >= 0 && s[count] != ' '){
            count--; ans--;
        }
        return s.size() - 1 - ans;
    }
};