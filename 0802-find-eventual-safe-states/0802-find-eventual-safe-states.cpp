class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int idx, vector<int>& visited) {
        if(visited[idx] == 2) return true;  // all the paths from this node are safe.
        
        if(visited[idx] == 1) return false;  // cycle detects.

        visited[idx] = 1;
        
        for(int i : graph[idx]) {
            if(! dfs(graph, i, visited)) return false;
        }
        
        visited[idx] = 2;
        
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> visited(n, 0);  // 0->not visited, 1->in current dfs, 2->confirm safed

        for(int i = 0; i < n; i++) {
            if(!visited[i]) dfs(graph, i, visited);
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(visited[i] == 2) ans.push_back(i);
        }

        return ans;
    }
};