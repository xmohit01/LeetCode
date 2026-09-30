class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int idx) {
        visited[idx] = true;

        for(int i = 0; i < n; i++) {
            if(i != idx && isConnected[idx][i] == 1 && !visited[i]) dfs(isConnected, visited, i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]){
                dfs(isConnected, visited, i);
                count++;
            }
        }

        return count;
    }
};