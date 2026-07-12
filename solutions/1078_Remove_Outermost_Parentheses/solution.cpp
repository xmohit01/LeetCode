class Solution {
public:
    string removeOuterParentheses(string s) {
        int temp = 0;
        string ans = "";
        for(char c : s){
            if(c == '('){
                temp++;
            }
            else{
                temp--;
            }
            if(temp == 1){
                if(c != '(') ans += c;
            }
            else if(temp > 1) ans += c;
        }
        return ans;
    }
};