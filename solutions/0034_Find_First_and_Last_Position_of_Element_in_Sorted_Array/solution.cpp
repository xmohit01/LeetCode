class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a= -1, b = -1;

        int st = 0, end = nums.size() - 1;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(nums[mid] == target){
                a = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target) st = mid + 1;
            else end = mid - 1;
        }
        st = 0, end = nums.size() - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;

            if(nums[mid] == target){
                b = mid;
                st = mid + 1;
            }
            else if(nums[mid] < target) st = mid + 1;
            else end = mid - 1;
        }
        return {a, b};
    }
};