class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int idx = 0;
        vector<int> v(m * n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ; j++){
                v[idx++] = grid[i][j];
            }
        }
        while(k--){
            int temp = v[m * n - 1];
            for(int i = m * n - 1; i > 0; i--){
                v[i] = v[i - 1];
            }
            v[0] = temp;
        }
        idx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ; j++){
                grid[i][j] = v[idx++];
            }
        }
        return grid;
    }
};