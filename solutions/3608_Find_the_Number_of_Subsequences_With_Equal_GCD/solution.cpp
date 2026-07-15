class Solution {
public:

    int MOD = 1e9 + 7;

    int helper(vector<int>& nums, int idx, int gcd1, int gcd2, vector<vector<vector<int>>>& dp){
        if(idx == nums.size()){
            if(gcd1 == gcd2) return 1;
            else return 0;
        }
        
        if(dp[idx][gcd1][gcd2] != -1) return dp[idx][gcd1][gcd2];

        int curr = nums[idx];

        long long n1 = helper(nums, idx + 1, gcd(gcd1, curr), gcd2, dp);

        long long n2 = helper(nums, idx + 1, gcd1, gcd(gcd2, curr), dp);

        long long n3 = helper(nums, idx + 1, gcd1, gcd2, dp);

        return dp[idx][gcd1][gcd2] = (n1 + n2 + n3) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {  
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(201, vector<int>(201, -1)));

        int ans = helper(nums, 0, 0, 0, dp);

        return ans - 1;
    }
};