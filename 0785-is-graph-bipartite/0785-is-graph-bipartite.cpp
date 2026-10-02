class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> m;

        for(int i = 0; i < graph.size(); i++) {
            if(m.count(i)) continue;
 
            queue<int> q;
            q.push(i);
            m[i] = 0;
    
            while(!q.empty()) {
                int currNode = q.front();
                int curr = m[currNode];
                q.pop();
    
                for(int node : graph[currNode]) {
                    if(m.count(node)) {
                        if(m[node] != 1 - curr) return false;
                    }
                    else {
                        m[node] = 1 - curr;
                        q.push(node);
                    }
                }
            }
        }
        
        return true;
    }
};