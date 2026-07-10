class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        // int k = -1;
        // for(int i = 1; i < n; i++){
        //     if(nums[i] < nums[i - 1]){
        //         k = i;
        //         break;
        //     }
        // }
        // if(k == -1) return true;

        // for(int i = k + 1; i < n; i++){
        //     if(nums[i] < nums[i - 1]) return false;
        // }
        // if(nums[0] < nums[n - 1]) return false;
        // return true;

        int count = 0;
        for(int i = 0; i < n - 1; i++){
            if(nums[i] > nums[i + 1]) count++;
        }
        if(nums[0] < nums[n - 1]) count++;

        return count <= 1;
    }
};