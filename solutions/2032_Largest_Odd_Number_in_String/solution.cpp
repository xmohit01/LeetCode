class Solution {
public:
    string largestOddNumber(string num) {
        int odd_idx = -1;
        for(int i = num.length() - 1; i >= 0; i--){
            if(num[i] % 2 == 1){
                odd_idx = i;
                break;
            }
        }
        if(odd_idx == -1) return "";
        string ans = num.substr(0, odd_idx + 1);
        return ans;
    }
};