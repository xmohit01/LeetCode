class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixSum = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1] + 1){
                prefixSum += nums[i];
            }
            else{
                break;
            }
        }

        vector<bool> seen(52, false);
        for(int num : nums){
            seen[num] = true;
        }

        while(prefixSum < 51 && seen[prefixSum]){
            prefixSum++;
        }
        return prefixSum;
    }
};