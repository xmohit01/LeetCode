class Solution {
public:
    int MOD = 1e9 + 7;
    
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] < a) nums[i] = -1;
            else if(nums[i] <= b) nums[i] = 0;
            else nums[i] = 1;
        }

        long long swaps = 0;
        long long ones = 0, zeros = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 1) ones++;

            else if(nums[i] == 0){
                swaps = (swaps + ones) % MOD;
                zeros++;
            }

            else{
                swaps = (swaps + ones + zeros) % MOD;
            }
        }
        return swaps;
    }
};