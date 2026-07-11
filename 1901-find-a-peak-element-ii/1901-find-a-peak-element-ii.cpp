class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int st_col = 0, end_col = n - 1;
        while(st_col <= end_col){
            int mid_col = st_col + (end_col - st_col) / 2;
            int row = 0;
            for(int i = 0; i < m; i++){
                if(mat[i][mid_col] > mat[row][mid_col]) row = i;
            }

            if((mid_col == 0 || mat[row][mid_col] > mat[row][mid_col - 1]) && (mid_col == n - 1 || mat[row][mid_col] > mat[row][mid_col + 1])) return {row, mid_col};

            else if((mid_col == 0 || mat[row][mid_col] > mat[row][mid_col - 1])) st_col = mid_col + 1;
            else end_col = mid_col - 1;
        }
        return {0, 0};
    }
};