class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                }
                else isWater[i][j] = -1;
            }
        }

        while(!q.empty()) {
            auto[row, col] = q.front();
            q.pop();
            
            for(int j = 0; j < 4; j++) {
                int nr = row + dr[j];
                int nc = col + dc[j];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && isWater[nr][nc] == -1) {
                    isWater[nr][nc] = isWater[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return isWater;
    }
};