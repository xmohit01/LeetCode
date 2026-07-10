class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);

        int n = s.length();
        int k = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '6'){
                k = i;
                break;
            }
        }
        if(k != -1) s[k] = '9';

        return stoi(s);
    }
};