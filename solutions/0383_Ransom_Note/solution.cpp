class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ch(26, 0);
        for(char c : magazine) ch[c - 'a']++;

        for(char c : ransomNote){
            if(ch[c - 'a'] <= 0) return false;
            else ch[c - 'a']--;
        }
        return true;
    }
};