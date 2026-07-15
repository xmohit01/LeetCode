class Solution {
public:

    int helper(vector<int>& nums, int idx, int limit, vector<int>& dp){
        if(idx < limit) return 0;
        if(idx == limit) return nums[idx];

        if(dp[idx] != -1) return dp[idx];

        int picked = nums[idx] + helper(nums, idx - 2, limit, dp);
        int not_picked = 0 + helper(nums, idx - 1, limit, dp);

        return dp[idx] = max(picked, not_picked);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        vector<int> dp(nums.size() + 1, -1);
        int ans1 = helper(nums, nums.size() - 2, 0, dp);

        fill(dp.begin(), dp.end(), -1);
        int ans2 = helper(nums, nums.size() - 1, 1, dp);

        return max(ans1, ans2);
    }
};