class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int n = word.size();
        for(int i = 0; i < n; ){
            char ch = word[i];
            int count = 0;
            while(i < n && word[i] == ch){
                i++;
                count++;
            }
            while(count >= 9){
                ans += '9';
                ans += ch;
                count -= 9;
            }
            if(count > 0){
                ans += count + '0';
                ans += ch;
            }
        }
        return ans;
    }
};