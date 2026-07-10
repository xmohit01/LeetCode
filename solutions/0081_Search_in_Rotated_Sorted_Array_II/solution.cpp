class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1, mid;

        while(st <= end){
            mid = st + (end - st) / 2;

            if(nums[mid] == target) return true;

            if(nums[st] == nums[mid] && nums[mid] == nums[end]){
                st++; end--; continue;
            }

            if(nums[st] <= nums[mid]){
                if(nums[st] <= target && nums[mid] > target)
                    end = mid - 1;
                else
                    st = mid + 1;
            }

            else{
                if(target > nums[mid] && target <= nums[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return false;
    }
};