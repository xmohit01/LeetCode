class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        vector<vector<int>> dp(n1, vector<int>(n2, 0));

        for(int j = 0; j < n2; j++) {
            if(text1[0] == text2[j]) {
                dp[0][j] = 1;
            }
            else if(j > 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for(int i = 0; i < n1; i++) {
            if(text1[i] == text2[0]) {
                dp[i][0] = 1;
            }
            else if(i > 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }
        
        int i = 1, j = 1;

        while(i < n1 && j < n2) {
            if(text1[i] == text2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                i++;
                j++;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

                i++;
                j++;
            }
        }

        for(int i = 1; i < n1; i++) {
            for(int j = 1; j < n2; j++) {

                if(text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n1 - 1][n2 - 1];
    }
};