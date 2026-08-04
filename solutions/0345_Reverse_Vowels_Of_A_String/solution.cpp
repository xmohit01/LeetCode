class Solution {
public:
    bool isVowel(char ch) {
        char lowerCh = tolower(ch);
        return (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u');
    }

    string reverseVowels(string s) {
        int st = 0, end = s.length() - 1;
        while(st <= end){
            while(st < s.length() && !isVowel(s[st])) st++;
            while(end >= 0 && !isVowel(s[end])) end--;

            if(st <= end)
            swap(s[st], s[end]);
            st++; end--;
        }
        return s;
    }
};