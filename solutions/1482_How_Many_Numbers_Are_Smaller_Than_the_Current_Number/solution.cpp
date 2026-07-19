class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num : nums) freq[num]++;

        for(int i = 1; i < 101; i++) freq[i] += freq[i - 1];

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) nums[i] = freq[nums[i] - 1];
        }

        return nums;
    }
};