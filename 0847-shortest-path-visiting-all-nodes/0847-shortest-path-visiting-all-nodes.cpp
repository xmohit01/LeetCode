class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        queue<vector<int>> q;
        vector<vector<bool>> vis(n, vector<bool>(1 << n, false));
        for(int i = 0; i < n; i++) {
            q.push({i, 1 << i , 0});
            vis[i][1 << i] = true;
        }

        int target = (1 << n) - 1;


        while(!q.empty()) {
            auto v = q.front();
            q.pop();

            int node = v[0];
            int mask = v[1];
            int dist = v[2];

            if(mask == target) return dist;

            for(int i : graph[node]) {
                int newMask = mask | (1 << i);
                if(vis[i][newMask]) continue;

                vis[i][newMask] = newMask;
                q.push({i, newMask, dist + 1});
            }
        }

        return -1;
    }
};