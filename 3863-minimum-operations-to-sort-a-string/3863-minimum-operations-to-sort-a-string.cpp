class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        string target = s;
        sort(target.begin(), target.end());

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != target[i]) cnt++;
        }

        if(cnt == 0) return 0;

        if(n == 2 && cnt == 2) return -1;

        if(s[0] == target[0] || s[n - 1] == target[n - 1]) return 1;

        int max_freq = count(s.begin(), s.end(), target[n - 1]);
        int min_freq = count(s.begin(), s.end(), target[0]);

        if (s[0] == target[n - 1] && max_freq == 1 && s[n - 1] == target[0] && min_freq == 1) {
            return 3;
        }

        return 2;
    }
};