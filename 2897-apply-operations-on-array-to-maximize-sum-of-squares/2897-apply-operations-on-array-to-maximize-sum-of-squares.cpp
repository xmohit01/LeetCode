class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        int MOD = 1000000007;

        vector<int> availableBits(32, 0);

        for(int& num : nums) {
            for(int i = 0; i < 32; i++) {

                if(num & (1 << i)) {
                    availableBits[i]++;
                }
            }
        }

        long long ans = 0;

        while(k--) {
            long long curr = 0;

            for(int i = 31; i >= 0; i--) {
                if(availableBits[i] > 0) {
                    curr = curr | (1 << i);

                    availableBits[i]--;
                }
            }

            ans = (ans + (curr * curr) % MOD) % MOD;
        }

        return ans;
    }
};