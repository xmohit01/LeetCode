class Solution {
public:
    string removeStars(string s) {
        int idx = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '*') idx--;
            else s[idx++] = s[i];
        }
        return s.substr(0, idx);
    }
};