class Solution {
public:
    int helper(vector<int>& stones, int& k, int st, int end, vector<vector<int>>& dp, vector<int>& preSum) {
        if(st >= end) return 0;

        if(dp[st][end] != -1) return dp[st][end];

        int minCost = INT_MAX;
        for(int i = st; i < end; i += k - 1) {
            int cost = helper(stones, k, st, i, dp, preSum) + helper(stones, k, i + 1, end, dp, preSum);

            minCost = min(minCost, cost);
        }

        if((end - st) % (k - 1) == 0) minCost += preSum[end + 1] - preSum[st];

        return dp[st][end] = minCost;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        if((n - 1) % (k - 1) != 0) return -1;

        vector<int> preSum(n + 1, 0);

        for(int i = 0; i < n; i++) {
            preSum[i + 1] = preSum[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(stones, k, 0, n - 1, dp, preSum);
    }
};