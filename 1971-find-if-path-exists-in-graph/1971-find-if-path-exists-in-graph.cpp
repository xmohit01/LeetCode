class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);

        for(auto& v : edges) {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }

        queue<int> q;
        q.push(source);

        vector<bool> vis(n, false);
        vis[source] = true;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            if(curr == destination) return true;

            for(int i : graph[curr]) {
                if(!vis[i]) {
                    vis[i] = true;

                    q.push(i);
                }
            }
        }

        return false;
    }
};