class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        long long sum = 0;
        vector<int> diff(n);

        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);

            sum += diff[i];
        }
        
        // Sort differences in descending order
        sort(diff.begin(), diff.end(), greater<int>());

        // Total number of operations available
        long long k = (long long)k1 + k2;

        // If we have enough operations to make all differences 0
        if(k >= sum) return 0;

        // Reduce the largest differences in groups
        for(int i = 0; i < n - 1; i++) {
            
            // Reducing first i maximums to (i + 1)th maximum.
            long long cost = 1LL * (i + 1) * (diff[i] - diff[i + 1]);

            // If we can Reducing then do it.
            if(k >= cost) k -= cost;

            else {
                // We don't have enough operations to reach the next level.

                // Number of times every element can be decreased
                long long decrease = k / (i + 1);

                // Remaining operations after equal distribution. These will decrease the first 'rem' elements once more.
                long long rem = k % (i + 1);

                for(int j = 0; j <= i; j++) {
                    diff[j] = diff[i] - decrease;

                    if(j < rem) diff[j]--;
                }

                // All available operations have now been used.
                k = 0;
                break;
            }
        }

        // If operations are still left, do the same thing with the last index we have done earlier.
        if(k > 0) {
            long long decrease = k / n;
            long long rem = k % n;

            for(int i = 0; i < n; i++) {
                diff[i] = diff[n - 1] - decrease;
                
                if(i < rem) diff[i]--;
            }
        }

        long long ans = 0;

        // Calculate the sum of squared differences.
        for(int i = 0; i < n; i++) {
            ans += 1LL * diff[i] * diff[i];
        }
        
        return ans;
    }
};