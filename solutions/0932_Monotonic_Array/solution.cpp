class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        bool isIncreasing = true;
        bool isDecreasing = true;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]){
                isIncreasing = false;
            }
            if(nums[i] < nums[i + 1]){
                isDecreasing = false;
            }
        }
        return isIncreasing || isDecreasing;
    }
};