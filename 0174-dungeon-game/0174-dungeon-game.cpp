class Solution {
public:
    int m, n;
    int helper(vector<vector<int>>& dungeon, int row, int col, vector<vector<int>>& dp){
        if(row >= m || col >= n) return 1e8;

        if(row == m - 1 && col == n - 1) return max(1, 1 - dungeon[row][col]);

        if(dp[row][col] != -1e9) return dp[row][col];

        int right = helper(dungeon, row, col + 1, dp);
        int down = helper(dungeon, row + 1, col, dp);

        return dp[row][col] = max(1, min(right, down) - dungeon[row][col]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1e9));

        return helper(dungeon, 0, 0, dp);
    }
};