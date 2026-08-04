class Solution {
public:
    string largestEven(string s) {
        int n = s.length();

        int i = n - 1;
        while(i >= 0 && s[i] != '2'){
            i--;
        }

        if(i == -1) return "";

        string ans = s.substr(0, i + 1);
        return ans;
    }
};