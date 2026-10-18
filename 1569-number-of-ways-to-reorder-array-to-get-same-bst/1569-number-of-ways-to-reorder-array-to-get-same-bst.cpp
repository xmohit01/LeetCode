class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<long long>> nCr;

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return 1; // Only one possible ordering.

        vector<int> left, right;

        // Split elements according to the root (first element)
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[0]) left.push_back(nums[i]);

            else right.push_back(nums[i]);
        }

        // Count valid reorderings of both subtrees.    
        long long leftWays = solve(left);
        long long rightWays = solve(right);

        // Choose positions for left or right subtree elements among n-1 positions
        long long ways = nCr[n - 1][left.size()];

        // Combine interleavings with both subtree reorderings
        ways = ways * leftWays % MOD;
        ways = ways * rightWays % MOD;
        
        return ways;
    }
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        nCr.assign(n + 1, vector<long long>(n + 1, 0));
        
        // Precompute combinations using Pascal's Triangle
        for(int i = 0; i <= n; i++) {
            nCr[i][0] = nCr[i][i] = 1;
            
            for(int j = 1; j < i; j++) {
                nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % MOD;
            }
        }

        // Exclude the given ordering.
        return (solve(nums) - 1 + MOD) % MOD;
    }
};