class Solution {
public:

    // int helper(vector<int>& nums, int idx, vector<int>& dp){
    //     if(idx < 0) return 0;
    //     if(idx == 0) return nums[0];

    //     if(dp[idx] != -1) return dp[idx];

    //     int picked = nums[idx] + helper(nums, idx - 2, dp);
    //     int not_picked = 0 + helper(nums, idx - 1, dp);

    //     return dp[idx] = max(picked, not_picked);
    // }

    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size() + 1, -1);
        // return helper(nums, nums.size() - 1, dp);

        int n = nums.size();
        int prev = nums[0], prev2 = 0;

        for(int i = 1; i < n; i++){
            int take = nums[i];
            if(i > 1) take += prev2;

            int not_take = 0 + prev;

            int curr = max(take, not_take);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};