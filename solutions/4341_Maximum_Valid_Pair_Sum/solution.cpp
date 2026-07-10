class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int max_i = 0;

        for (int j = k; j < n; ++j) {
            max_i = max(max_i, nums[j - k]);
            
            ans = max(ans, max_i + nums[j]);
        }
        
        return ans;
    }
};