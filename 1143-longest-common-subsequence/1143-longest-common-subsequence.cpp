class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        vector<vector<int>> dp(n1, vector<int>(n2, 0));

        // Initialize first row
        for(int j = 0; j < n2; j++) {
            if(text1[0] == text2[j]) {
                dp[0][j] = 1;
            }
            else if(j > 0) {
                dp[0][j] = dp[0][j - 1];
            }
        }

        // Initialize first column
        for(int i = 0; i < n1; i++) {
            if(text1[i] == text2[0]) {
                dp[i][0] = 1;
            }
            else if(i > 0) {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Fill the DP table
        for(int i = 1; i < n1; i++) {
            for(int j = 1; j < n2; j++) {

                // Matching characters can be included
                if(text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    // Skip one character from either string
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n1 - 1][n2 - 1];
    }



    // METHOD 2

    // int helper(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
    //     if(i < 0 || j < 0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(text1[i] == text2[j]) {
    //         return dp[i][j] = 1 + helper(text1, text2, i - 1, j - 1, dp);
    //     }

    //     return dp[i][j] = max(helper(text1, text2, i - 1, j, dp), helper(text1, text2, i, j - 1, dp));
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     int n1 = text1.size();
    //     int n2 = text2.size();

    //     vector<vector<int>> dp(n1, vector<int>(n2, -1));

    //     return helper(text1, text2, text1.size() - 1, text2.size() - 1, dp);
    // }
};