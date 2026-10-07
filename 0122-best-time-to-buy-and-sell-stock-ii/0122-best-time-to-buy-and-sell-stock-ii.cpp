class Solution {
public:
    int n;
    int helper(vector<int>& prices, int idx, int buy, vector<vector<int>>& dp) {
        if(idx >= n) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int maxi = INT_MIN;

        if(buy == 1) {
            // buy today
            maxi = max(maxi, - prices[idx] + helper(prices, idx + 1, 0, dp));

            // skip today to buy
            maxi = max(maxi, helper(prices, idx + 1, 1, dp));
        }
        
        else {
            // sell today
            maxi = max(maxi, prices[idx] + helper(prices, idx + 1, 1, dp));

            // skip today to sell
            maxi = max(maxi, helper(prices, idx + 1, 0, dp));
        }
        
        return dp[idx][buy] = maxi;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return helper(prices, 0, 1, dp);
    }
};