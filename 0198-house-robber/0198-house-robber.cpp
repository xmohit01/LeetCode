class Solution {
public:

    int helper(vector<int>& nums, int idx, vector<int>& dp){
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];

        if(dp[idx] != -1) return dp[idx];

        int picked = nums[idx] + helper(nums, idx - 2, dp);
        int not_picked = 0 + helper(nums, idx - 1, dp);

        return dp[idx] = max(picked, not_picked);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return helper(nums, nums.size() - 1, dp);
    }
};