class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = 0, c = matrix[0].size() - 1;
        while(c >= 0 && r < matrix.size()){
        if(matrix[r][c] == target) return true;
        else if(target > matrix[r][c]) r++;
        else if(target < matrix[r][c]) c--;
        }
        return false;
    }
};