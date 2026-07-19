class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.length();

        int vowels = 0;
        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) vowels++;
        }

        int temp = vowels;
        for(int i = k; i < n; i++){
            if(isVowel(s[i])) temp++;

            if(isVowel(s[i - k])) temp--;
            
            vowels = max(vowels, temp);
        }
        return vowels;
    }
};