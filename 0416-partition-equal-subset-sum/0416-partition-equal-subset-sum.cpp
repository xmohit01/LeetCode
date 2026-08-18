class Solution {
public:
    int n;
    bool helper(vector<int>& nums, int idx, int target, vector<vector<int>>& dp){
        if(target == 0) return true;

        if(idx >= n) return false;

        if(target < 0) return false;

        if(dp[idx][target] != -1) return dp[idx][target];

        bool notTaken = helper(nums, idx + 1, target, dp);
        bool taken = helper(nums, idx + 1, target - nums[idx], dp);

        return dp[idx][target] = notTaken || taken;
    }

    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for(int num : nums) sum += num;

        if(sum % 2 == 1) return false;
        
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return helper(nums, 0, target, dp);
    }
};