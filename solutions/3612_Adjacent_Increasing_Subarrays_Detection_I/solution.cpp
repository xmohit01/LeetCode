class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k == 1) return true;
        int n = nums.size();
        int times= 0;

        for(int i = 0; i <= n - 2 * k; i++){
            bool firstHalf = true, secondHalf = true;

            for(int j = i; j < i + k - 1; j++){
                if(nums[j] >= nums[j + 1]){
                    firstHalf = false;
                    break;
                }
            }

            for(int j = i + k; j < i + 2 * k - 1; j++){
                if(nums[j] >= nums[j + 1]){
                    secondHalf = false;
                    break;
                }
            }
            if(firstHalf && secondHalf) return true;
        }

        return false;
    }
};