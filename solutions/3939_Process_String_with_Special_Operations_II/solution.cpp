class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> len(n, 0);

        long long curr_len = 0;
        for(int i = 0; i < n; i++){

            if(s[i] >= 'a' && s[i] <= 'z') curr_len++;

            else if(s[i] == '*'){
                curr_len = max(0LL, curr_len - 1);
            }

            else if(s[i] == '#') curr_len *= 2;

            len[i] = curr_len;
        }

        if(k < 0 || k >= len[n - 1]) return '.';

        for(int i = n - 1; i >= 0; i--){
            long long prev_len = (i > 0) ? len[i - 1] : 0;

            if(prev_len == 0 && s[i] == '*' && (s[i] < 'a' || s[i] > 'z')) continue;

            if(s[i] >= 'a' && s[i] <= 'z'){
                if(k == prev_len) return s[i]; 
            }

            else if(s[i] == '#') k %= prev_len;

            else if(s[i] == '%') k = prev_len - k - 1;
        }

        return '.';
    }
};