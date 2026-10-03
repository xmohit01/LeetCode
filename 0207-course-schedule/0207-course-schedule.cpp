class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& pathVisited, int idx) {
        visited[idx] = true;
        pathVisited[idx] = true;

        for(int i : graph[idx]) {
            if(!visited[i]) {
                // If DFS from this node finds a cycle, propagate it back
                if(dfs(graph, visited, pathVisited, i)) return true;
            }
            else if(pathVisited[i]) {
                // Node is already in current DFS path -> directed cycle found
                return true;
            }
        }

        // Leaving this node, so it is no longer part of the current DFS path
        pathVisited[idx] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        // [a,b] means b -> a: complete b before a
        for(auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathVisited(numCourses, false);

        // Check every component of the graph for a cycle
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                // dfs() returns true if a cycle is found
                if(dfs(graph, visited, pathVisited, i)) return false;
            }
        }

        // No cycle found -> all courses can be completed
        return true;
    }
};