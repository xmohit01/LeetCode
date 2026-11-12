class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1) return -1;

        if(n == 1) return 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int dist = 1;

        while(!q.empty()) {
            int sz = q.size();

            dist++;

            for(int k = 0; k < sz; k++) {
                auto p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                for(int i = -1; i <= 1; i++) {
                    for(int j = -1; j <= 1; j++) {
                        int dr = r + i;
                        int dc = c + j;

                        if(dr >= 0 && dc >= 0 && dr < n && dc < n && grid[dr][dc] == 0) {

                            if(dr == n - 1 && dc == n - 1) return dist;

                            grid[dr][dc] = 1;

                            q.push({dr, dc});
                        }
                    }
                }
            }
        }

        return -1;
    }
};