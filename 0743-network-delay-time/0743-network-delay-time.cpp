class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for(auto& v : times) {
            graph[v[0]].push_back({v[1], v[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        pq.push({0, k});

        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int d = p.first;
            int u = p.second;

            if(d > dist[u]) continue;

            for(auto& p : graph[u]) {
                int v = p.first;
                int time = p.second;

                if(dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;

                    pq.push({dist[v], v});
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());

        return ans == 1e9 ? -1 : ans;
    }
};