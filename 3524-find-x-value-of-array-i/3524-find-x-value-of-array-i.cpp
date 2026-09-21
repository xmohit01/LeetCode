class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k, 0);
        vector<long long> ans(k, 0);

        for(int num : nums){
            vector<long long> temp(k, 0);
            
            temp[num % k]++;

            for(int r = 0; r < k; r++){
                long long newRem = (1LL * r * num) % k;
                temp[newRem] += dp[r];
            }

            for(int r = 0; r < k; r++){
                ans[r] += temp[r];
            }

            dp = temp;
        }

        return ans;
    }
};