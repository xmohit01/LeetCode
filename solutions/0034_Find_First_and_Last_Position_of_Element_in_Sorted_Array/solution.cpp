class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = -1;
        int i;
        for(i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                a = i;
                break;
            }
        }
        int b = -1;
        for(i = a; i < nums.size(); i++){
            if(nums[i] == target) b = i;
        }
        return {a, b};
    }
};