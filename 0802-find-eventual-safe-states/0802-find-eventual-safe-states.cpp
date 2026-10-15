class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int idx, vector<int>& visited, vector<int>& ans) {
        if(visited[idx] == 2) return true;
        
        if(visited[idx] == 1) return false;

        visited[idx] = 1;

        if(graph[idx].empty()) visited[idx] = 2;

        for(int i : graph[idx]) {
            if(! dfs(graph, i, visited, ans)) return false;
        }
        
        ans.push_back(idx);
        visited[idx] = 2;
        
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> ans;
        vector<int> visited(n, 0);  // 0->not visited, 1->in current dfs, 2->confirm safed
        for(int i = 0; i < n; i++) {
            if(!visited[i]) dfs(graph, i, visited, ans);
        }

        sort(ans.begin(), ans.end());
        
        return ans;
    }
};