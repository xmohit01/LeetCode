class Solution {
public:
    long long MOD = 1000000007;
    int m, n;
    pair<long long, long long> helper(vector<vector<int>>& grid, int row, int col, vector<vector<pair<long long, long long>>>& dp){

        if(row == m - 1 && col == n - 1){
            return {grid[row][col], grid[row][col]};
        }

        if(dp[row][col] != make_pair((long long)INT_MIN, (long long)INT_MAX)) return dp[row][col];

        long long currMax = -1e18;
        long long currMin = 1e18;
        
        if(row < m - 1){
            pair<long long, long long> down = helper(grid, row + 1, col, dp);

            long long a = grid[row][col] * down.first;
            long long b = grid[row][col] * down.second;
            currMax = max({currMax, a, b});
            currMin = min({currMin, a, b});
        }
        if(col < n - 1){
            pair<long long, long long> right = helper(grid, row, col + 1, dp);

            long long a = grid[row][col] * right.first;
            long long b = grid[row][col] * right.second;
            currMax = max({currMax, a, b});
            currMin = min({currMin, a, b});
        }
        return dp[row][col] = {currMax, currMin};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n, {INT_MIN, INT_MAX}));

        long long ans = (helper(grid, 0, 0, dp)).first;
        return ans < 0 ? -1 : ans % MOD;
    }
};