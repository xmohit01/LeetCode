class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int ones = 0, zeros = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') ones++;
            else zeros++;
        }

        string ans = "";
        ones--;
        while(ones--) ans += '1';
        while(zeros--) ans += '0';
        ans += '1';

        return ans;
    }
};