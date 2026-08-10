class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if(m * n != r * c) return mat;

        vector<vector<int>> ans(r, vector<int>(c, 0));

        for(int i = 0; i < m * n; i++){
            int oldRow = i / n;
            int oldCol = i % n;

            int newRow = i / c;
            int newCol = i % c;

            ans[newRow][newCol] = mat[oldRow][oldCol];
        }
        return ans;
    }
};