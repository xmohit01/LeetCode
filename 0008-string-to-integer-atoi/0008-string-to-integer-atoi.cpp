class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        while(i < n && s[i] == ' ') i++;

        bool pos = true;
        if(i < n){
            if(s[i] == '-'){
                pos = false;
                i++;
            }
            else if(s[i] == '+'){
                i++;
            }
        }

        long long ans = 0;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            ans = ans * 10 + (s[i] - '0');

            if(pos){
                if(ans > INT_MAX) return INT_MAX;
            }
            else{
            if(-ans < INT_MIN) return INT_MIN;
            }

            i++;
        }
        if(pos) return (int)ans;
        return (int)-ans;
    }
};