class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) q.push({i, j});
                    
                else mat[i][j] = -1;
            }
        }

        while(!q.empty()) {
            auto[row, col] = q.front();
            q.pop();
            
            for(int j = 0; j < 4; j++) {
                int nr = row + dr[j];
                int nc = col + dc[j];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == -1) {
                    mat[nr][nc] = mat[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }
        
        return mat;
    }
};