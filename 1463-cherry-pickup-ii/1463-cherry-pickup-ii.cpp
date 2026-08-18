class Solution {
public:
    int m, n;
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> prev(n, vector<int>(n, 0));
        vector<vector<int>> curr(n, vector<int>(n, 0));

        for(int j1 = 0; j1 < n; j1++){
            for(int j2 = 0; j2 < n; j2++){
                if(j1 == j2) prev[j1][j2] = grid[m - 1][j1];
                else prev[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        for(int i = m - 2; i >= 0; i--){
            for(int j1 = 0; j1 < n; j1++){
                for(int j2 = 0; j2 < n; j2++){
                    int maxi = INT_MIN;
                    for(int idx1 = j1 - 1; idx1 <= j1 + 1; idx1++){
                        if(idx1 >= 0 && idx1 < n){
                            for(int idx2 = j2 - 1; idx2 <= j2 + 1; idx2++){
                                if(idx2 >= 0 && idx2 < n){
                                    int curr = j1 != j2 ? grid[i][j1] + grid[i][j2] + prev[idx1][idx2] : grid[i][j2] + prev[idx1][idx2];

                                    maxi = max(maxi, curr);
                                }
                            }
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            prev = curr;
        }
        return prev[0][n - 1];
    }
};