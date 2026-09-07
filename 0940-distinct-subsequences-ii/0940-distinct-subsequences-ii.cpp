class Solution {
public:
    int distinctSubseqII(string s) {
        long long MOD = 1e9 + 7;

        vector<int> dp(26, 0);

        long long total = 0;
        for(char c : s){
            int currIdx = c - 'a';

            // Har existing subsequence ke end mein current c laga do + empty subsequence ke end mein c laga do.
            long long newCount = total + 1;
            // dp[currIdx] contains the OLD number of
            // subsequences ending with this same character.

            total = total -  dp[currIdx] + newCount + MOD;
            total %= MOD;
            // We REMOVE that old group because the new group already contains all of them (otherwise duplicates would be counted).

            dp[currIdx] = newCount % MOD;
            // The new group of subsequences ending with c becomes the current/latest group for this character.
        }

        return total;
    }
};