class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], temp = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(temp > 0) temp += nums[i];
            else temp = nums[i];
            
            ans = max(ans, temp);
        }
        return ans;
    }
};