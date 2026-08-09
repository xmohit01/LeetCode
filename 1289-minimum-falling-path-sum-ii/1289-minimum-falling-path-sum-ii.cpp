class Solution {
public:
    int n;
    int helper(vector<vector<int>>& grid, int lastIdx, int currIdx, vector<vector<int>>& dp){
        if(dp[currIdx][lastIdx + 1] != -1) return dp[currIdx][lastIdx + 1];
        if(currIdx == 0){
            int mini = INT_MAX;

            for(int i = 0; i < n; i++){
                if(i != lastIdx){
                    mini = min(mini, grid[currIdx][i]);
                }
            }
            return dp[currIdx][lastIdx + 1] = mini;
        }

        int points;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(i != lastIdx){
                points = grid[currIdx][i] + helper(grid, i, currIdx - 1, dp);

                mini = min(mini, points);
            }
        }

        return dp[currIdx][lastIdx + 1] = mini;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return helper(grid, -1, n - 1, dp);
    }
};