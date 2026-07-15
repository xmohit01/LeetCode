class Solution {
public:

    int helper(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) return 0;

        grid[row][col] = 0;
        int up = helper(grid, row - 1, col);
        int down = helper(grid, row + 1, col);
        int left = helper(grid, row, col - 1);
        int right = helper(grid, row, col + 1);

        return 1 + up + down + left + right;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int temp = helper(grid, i, j);

                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};