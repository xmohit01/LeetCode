class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int mid;
        while(st <= end){
            mid = st + (end - st) / 2;
            if(target == nums[mid]) return mid;

            if(nums[st] <= nums[mid])
            (nums[st] <= target) && (target <= nums[mid]) ? end = mid - 1 : st = mid + 1;
            else
            (nums[end] >= target) && (target >= nums[mid]) ? st = mid + 1 : end = mid - 1;
        }
        return -1;
    }
};