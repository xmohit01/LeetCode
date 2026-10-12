class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0, mask = 0;

        // Try to eliminate bits from highest to lowest
        for(int i = 29; i >= 0; i--) {
            int bit = (1 << i);

            int curr = -1; // AND of the current group
            int count = 0; // Count elements that still have forbidden bits

            for(int j = 0; j < n; j++) {
                // Calculate AND of the current group
                curr = curr & nums[j];

                // Check if all bits we want to eliminate are zero
                if((curr & (mask | bit)) == 0) {
                    // Current group is valid, start a new group
                    curr = (1 << 30) - 1;
                }
                else {
                    // Current group still contains a forbidden bit
                    count++;
                }
            }

            // If more than k operations are needed, keep this bit
            if(count > k) ans = ans | bit;

            // Otherwise, try to eliminate this bit too
            else mask = mask | bit;
        }

        return ans;
    }
};