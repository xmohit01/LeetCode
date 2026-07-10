class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // vector<pair<int, int>> pairs;
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(matrix[i][j] == 0){
        //             pairs.push_back({i, j});
        //         }
        //     }
        // }
        // for(auto& p : pairs){
        //     int row = p.first;
        //     int column = p.second;
        //     for(int i = 0; i < n; i++) matrix[row][i] = 0;
        //     for(int i = 0; i < m; i++) matrix[i][column] = 0;
        // }

        vector<int> rows(m, 0);
        vector<int> cols(n, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    rows[i] = cols[j] = 1;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rows[i] == 1 || cols[j] == 1){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};