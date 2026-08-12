class Solution {
public:
    int m, n;
    int helper(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int currRow, int currCol){
        if(obstacleGrid[currRow][currCol] == 1) return 0;

        if(currRow == m - 1 && currCol == n - 1) return 1;

        if(dp[currRow][currCol] != -1) return dp[currRow][currCol];

        int rowWise = 0;
        if(currRow < m - 1) rowWise = helper(obstacleGrid, dp, currRow + 1, currCol);
        int colWise = 0;
        if(currCol < n - 1) colWise = helper(obstacleGrid, dp, currRow, currCol + 1);

        return dp[currRow][currCol] = rowWise + colWise;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(obstacleGrid, dp, 0, 0);
    }
};