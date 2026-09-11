class Solution {
public:
    struct State {
        int r;
        int c;
        int energy;
        int moves;
        string collected;
    };

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        int countL = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(classroom[i][j] == 'S'){
                    sr = i;
                    sc = j;
                }
                if(classroom[i][j] == 'L') countL++;
            }
        }

        if(countL == 0) return 0;

        // Give each L a unique ID
        vector<vector<int>> id(m, vector<int>(n, -1));
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(classroom[i][j] == 'L'){
                    id[i][j] = cnt++;
                }
            }
        }

        queue<State> q;
        string collected(countL, '0'); // 0 = not collected, 1 = collected
        q.push({sr, sc, energy, 0, collected});

        // visited[row][col][energy][collectedId]
        vector<vector<vector<vector<bool>>>> visited(m, vector<vector<vector<bool>>>
        (n, vector<vector<bool>>(energy + 1, vector<bool>(1 << countL, false))));

        visited[sr][sc][energy][0] = true;

        while(!q.empty()){
            State curr = q.front();
            q.pop();

            int r = curr.r;
            int c = curr.c;
            int energyLeft = curr.energy;
            int moves = curr.moves;

            if(energyLeft == 0) continue;

            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for(int d = 0; d < 4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

                if(classroom[nr][nc] == 'X') continue;

                // One move uses one energy
                int newEnergy = energyLeft - 1;

                // R restores energy
                if(classroom[nr][nc] == 'R') newEnergy = energy;

                string collected = curr.collected;

                // Mark L as collected
                if(classroom[nr][nc] == 'L'){
                    collected[id[nr][nc]] = '1';
                }

                int collectedId = 0;
                // Convert string to a number for visited
                for(int i = 0; i < countL; i++){
                    if(collected[i] == '1'){
                        collectedId += (1 << i);
                    }
                }

                // All L collected
                if(collectedId == (1 << countL) - 1)
                    return moves + 1;

                // Skip already visited state
                if(visited[nr][nc][newEnergy][collectedId]) continue;

                visited[nr][nc][newEnergy][collectedId] = true;

                q.push({nr, nc, newEnergy, moves + 1, collected});
            }
        }

        return -1;
    }
};