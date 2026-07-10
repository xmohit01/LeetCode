class Solution {
public:

    int helper(int target, vector<int> &vec){
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(vec[target] != -1) return vec[target];

        return vec[target] = helper(target - 1, vec) + helper(target - 2, vec);
    }

    int climbStairs(int n) {
        vector<int> vec(n + 1, -1);

        return helper(n, vec);
    }
};