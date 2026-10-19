class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lesser = 0, greater = nums.size();

        for(int& num : nums) {
            if(num > target) greater--;

            else if(num < target) lesser++;
        }

        vector<int> ans;
        for(int i = lesser; i < greater; i++) ans.push_back(i);

        return ans;
    }
};