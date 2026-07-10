class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size();

        int st_row = 0, end_row = rows - 1;
        int mid_row = st_row + (end_row - st_row) / 2;

        while(st_row <= end_row){
            if(matrix[mid_row][0] <= target && target <= matrix[mid_row][columns - 1]) break;
            else if(matrix[mid_row][columns - 1] < target) st_row = mid_row + 1;
            else if(matrix[mid_row][0] > target) end_row = mid_row - 1;

            mid_row = st_row + (end_row - st_row) / 2;
        }
        if(st_row > end_row)
            return false;
        int st_col = 0, end_col = columns - 1;
        int mid_col = st_col + (end_col - st_col) / 2;
        while(st_col <= end_col){
            if(matrix[mid_row][mid_col] == target) return true;
            else if(matrix[mid_row][mid_col] > target) end_col = mid_col - 1;
            else if(matrix[mid_row][mid_col] < target) st_col = mid_col + 1;;

            mid_col = st_col + (end_col - st_col) / 2;
        }

        return false;

    }
};