class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int idx = 0;
        vector<int> v(m * n);
        k %= (m * n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ; j++){
                v[idx++] = grid[i][j];
            }
        }
        reverse(v.end() - k, v.end());
        reverse(v.begin(), v.end() - k);
        reverse(v.begin(), v.end());
        idx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ; j++){
                grid[i][j] = v[idx++];
            }
        }
        return grid;
    }
};