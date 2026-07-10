class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prev_sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prev_sum += nums[i];
            nums[i] = prev_sum;
        }
        return nums;
    }
};