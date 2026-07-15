class Solution {
public:

    void helper(vector<vector<char>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0') return;
        else grid[row][col] = '0';

        helper(grid, row - 1, col);
        helper(grid, row + 1, col);
        helper(grid, row, col - 1);
        helper(grid, row, col + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    count++;

                    helper(grid, i, j);
                }
            }
        }
        return count;
    }
};