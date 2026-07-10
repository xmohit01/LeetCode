class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat[0].size();
        vector <int> x(2, 0);
        int max = 0;
        for(int i = 0; i < rows; i++){
            int count = 0;
            for(int j = 0; j < columns; j++){
                if(mat[i][j] == 1) count ++;
            }
            if(max < count){
                max = count;
                x[0] = i; x[1] = count;
            }
        }
        return x;
    }
};