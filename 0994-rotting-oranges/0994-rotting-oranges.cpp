class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> rotten;
        int freshOranges = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) rotten.push({i, j});
                else if(grid[i][j] == 1) freshOranges++;
            }
        }
        if(freshOranges == 0) return 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minutes = 0;

        while(!rotten.empty()){
            int size = rotten.size();
            bool rotted = false;
            
            for(int i = 0; i < size; i++){

                auto index = rotten.front();
                rotten.pop();

                for(auto direction : directions){
                    int row = index.first + direction.first;
                    int col = index.second + direction.second;

                    if(row >= 0 && col >= 0 && row < m && col < n && grid[row][col] == 1){
                        grid[row][col] = 2;
                        freshOranges--;
                        rotted = true;
                        rotten.push({row, col});
                    }
                }
            }
            if(rotted) minutes++;
        }
        return freshOranges == 0 ? minutes : -1;
    }
};