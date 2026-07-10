class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // int m = matrix.size();
        // if(m == 1) return true;
        // int n = matrix[0].size();
        // for(int j = 0; j < n; j++){
        //     int row = 0;
        //     int temp = matrix[row][j];
        //     int col = j;
        //     while(row < m && col < n){
        //         if(matrix[row++][col++] != temp) return false;
        //     }
        // }
        // for(int i = 0; i < m; i++){
        //     int col = 0;
        //     int temp = matrix[i][col];
        //     int row = i;
        //     while(row < m && col < n){
        //         if(matrix[row++][col++] != temp) return false;
        //     }
        // }
        // return true;

        for(int i = 0; i < matrix.size() - 1; i++){
            for(int j = 0; j < matrix[0].size() - 1; j++){
                if(matrix[i][j] != matrix[i + 1][j + 1]) return false;
            }
        }
        return true;
    }
};