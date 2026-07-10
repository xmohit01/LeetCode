class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        int idx = -1;
        for(int i = 0; i < n; i++){
            if(word[i] == ch){
                idx = i;
                break;
            }
        }

        if(idx == -1) return word;

        int st = 0, end = idx;
        while(st <= end){
            swap(word[st], word[end]);
            st++; end--;
        }

        return word;
    }
};