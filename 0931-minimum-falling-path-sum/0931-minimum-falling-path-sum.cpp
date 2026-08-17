class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n);
        for(int i = 0; i < n; i++) prev[i] = matrix[0][i];

        for(int i = 1; i < n; i++){
            vector<int> curr(n);

            for(int j = 0; j < n; j++){
                int up = matrix[i][j] + prev[j];

                int left = j > 0 ? matrix[i][j] + prev[j - 1] : 1e9;

                int right = j < n - 1 ? matrix[i][j] + prev[j + 1] : 1e9;

                curr[j] = min({up, left, right});
            }
            prev = curr;
        }

        int ans = INT_MAX;
        for(int num : prev) ans = min(ans, num);

        return ans;
    }
};