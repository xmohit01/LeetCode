class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, int idx, vector<int>& ans) {
        visited[idx] = true;
        pathVisited[idx] = true;

        for(int i : graph[idx]) {
            if(!visited[i]) {
                // Go deeper first. We will add idx to ans only after coming back from this DFS
                if(dfs(graph, visited, pathVisited, i, ans)) return true;
            }
            else if(pathVisited[i]) {
                // Node is already in the current DFS path -> directed cycle found
                return true;
            }
        }

        // All neighbours are finished. We are now coming back from idx, so add idx to ans. This gives the {reverse topological} order
        ans.push_back(idx);

        // We are leaving idx, so it is no longer part of the current DFS path
        pathVisited[idx] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        // [a,b] means b -> a: complete b before a
        for(auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        vector<int> ans;

        // Check every component of the graph for a cycle
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                // If DFS finds a cycle, no valid course order exists
                if(dfs(graph, visited, pathVisited, i, ans)) return {};
            }
        }

        // DFS added courses while coming back, so ans is in reverse order.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};