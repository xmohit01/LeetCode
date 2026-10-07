class Solution {
public:
    int n, f;
    int helper(vector<int>& prices, int idx, int buy, vector<vector<int>>& dp) {
        if(idx >= n) return 0;

        // Already calculated this state
        if(dp[idx][buy] != -1) return dp[idx][buy];

        if(buy == 1) {
            // We don't have a stock, so either buy today or skip
            return dp[idx][buy] = max(
                - prices[idx] + helper(prices, idx + 1, 0, dp), // Buy today
                helper(prices, idx + 1, 1, dp)                  // Skip today
            );
        }
        
        else {
            return dp[idx][buy] = max(
                prices[idx] - f + helper(prices, idx + 1, 1, dp), // Sell today ans also pay fee here 
                helper(prices, idx + 1, 0, dp)                // Skip today
            );
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        f = fee;

        // dp[idx][buy]:
        // Maximum profit from idx onwards with current buy state
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Initially, we don't own any stock, so we can buy
        return helper(prices, 0, 1, dp);
    }
};