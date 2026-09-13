class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& dp, int currRow, int currCol){
        if(currRow == m - 1 || currCol == n - 1) return 1;

        if(dp[currRow][currCol] != -1) return dp[currRow][currCol];

        int rowWise = helper(m, n, dp, currRow + 1, currCol);
        int colWise = helper(m, n, dp, currRow, currCol + 1);

        return dp[currRow][currCol] = rowWise + colWise;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(m, n, dp, 0, 0);
    }
};