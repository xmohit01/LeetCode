class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int end = -1;
        int max_ = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] < max_) end = i;
            else max_ = nums[i];
        }

        if(end == -1) return 0;

        int st = 0;
        int min_ = nums[n - 1];

        for(int i = n - 2; i >= 0; i--){
            if(nums[i] > min_) st = i;
            else min_ = nums[i];
        }

        return end - st + 1;
    }
};