class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;
        return (count(nums.begin(), nums.end(), nums[mid]) == 1);
    }
};