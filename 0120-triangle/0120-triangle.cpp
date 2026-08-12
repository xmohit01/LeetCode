class Solution {
public:
    int size;
    int helper(vector<vector<int>>& triangle, int currRow, int currCol, vector<vector<int>>& dp){
        if(currRow == size - 1){
            return triangle[currRow][currCol];
        }

        if(dp[currRow][currCol] != INT_MAX) return dp[currRow][currCol];

        int leftJump = helper(triangle, currRow + 1, currCol, dp);
        int rightJump = helper(triangle, currRow + 1, currCol + 1, dp);

        return dp[currRow][currCol] = triangle[currRow][currCol] + min(leftJump, rightJump);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        size = triangle.size();
        vector<vector<int>> dp(size, vector<int>(size, INT_MAX));

        return helper(triangle, 0, 0, dp);
    }
};