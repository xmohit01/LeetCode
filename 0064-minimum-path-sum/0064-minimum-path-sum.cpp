class Solution {
public:
    int m, n;
    int helper(vector<vector<int>>& grid,int currRow, int currCol, vector<vector<int>>& dp){
        if(currRow == m - 1 && currCol == n - 1) return grid[currRow][currCol];

        if(dp[currRow][currCol] != -1) return dp[currRow][currCol];

        int rowWise = (currRow < m - 1) ? helper(grid, currRow + 1, currCol, dp) : INT_MAX;
        int colWise = (currCol < n - 1) ? helper(grid, currRow, currCol + 1, dp) : INT_MAX;

        return dp[currRow][currCol] = grid[currRow][currCol] + min(rowWise, colWise);
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(grid, 0, 0, dp);
    }
};