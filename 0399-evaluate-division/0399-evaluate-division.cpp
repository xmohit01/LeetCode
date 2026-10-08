class Solution {
public:
    double dfs(unordered_map<string, vector<pair<string, double>>>& graph, string& st, string& end, unordered_set<string>& visited, double product) {
        visited.insert(st);

        if(st == end) return product;

        for(auto& p : graph[st]) {
            if(visited.count(p.first)) continue;

            double ans = dfs(graph, p.first, end, visited, product * p.second);

            if(ans != -1.0) return ans;
        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();

        unordered_map<string, vector<pair<string, double>>> graph;

        for(int i = 0; i < n; i++) {
            auto& p = equations[i];
            double currVal = values[i];
            
            graph[p[0]].push_back({p[1], currVal});
            graph[p[1]].push_back({p[0], 1 / currVal});
        }

        vector<double> result(queries.size(), -1);

        for(int i = 0; i < queries.size(); i++) {
            auto& querie = queries[i];
            unordered_set<string> visited;

            string start = querie[0];
            string end = querie[1];

            if(!graph.count(start) || !graph.count(end)) continue;

            result[i] = dfs(graph, start, end, visited, 1.0);
        }

        return result;
    }
};