class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> freq(26);
        for(char c : s) freq[c - 'a']++;

        int idx = 0;
        for(int i = 0; i < 26; i++){
            char c = i + 'a';

            while(freq[i] > 1){
                s[idx] = c;
                s[n - idx - 1] = c;

                idx++;
                freq[i] -= 2;
            }
            if(freq[i] == 1){
                s[n / 2] = c;
            }
        }
        return s;
    }
};