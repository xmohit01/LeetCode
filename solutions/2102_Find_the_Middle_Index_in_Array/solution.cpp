class Solution {
public:

    bool check(vector<int>& nums, int idx){
        int n = nums.size();
        int leftSum = 0, rightSum = 0;
        if(idx == 0){
            leftSum = 0;
            for(int i = 1; i < n; i++) rightSum += nums[i];
        }
        else if(idx == n - 1){
            rightSum = 0;
            for(int i = 0; i < n - 1; i++) leftSum += nums[i];
        }
        else{
            for(int i = 0; i < idx; i++) leftSum += nums[i];
            for(int i = idx + 1; i < n; i++) rightSum += nums[i];
        }

        return leftSum == rightSum;
    }

    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
    
        for(int i = 0; i < n; i++){
            if(check(nums, i)) return i;
        }

        return -1;
    }
};