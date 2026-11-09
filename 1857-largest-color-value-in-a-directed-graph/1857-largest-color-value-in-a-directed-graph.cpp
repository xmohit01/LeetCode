class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();

        vector<vector<int>> graph(n);

        // [a,b] means b -> a: complete b before a
        for(auto& p : edges) {
            graph[p[0]].push_back(p[1]);
        }

        vector<int> inDeg(n, 0);
        for(auto& p : edges) {
            inDeg[p[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));

        int ans = INT_MIN, cnt = 0;

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(inDeg[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            cnt++;

            dp[node][colors[node] - 'a']++;

            ans = max(ans, dp[node][colors[node] - 'a']);

            for(int i : graph[node]) {
                inDeg[i]--;

                for(int j = 0; j < 26; j++) {
                    dp[i][j] = max(dp[i][j], dp[node][j]);
                }

                if(inDeg[i] == 0) q.push(i);
            }
        }

        if(cnt != n) return -1;

        return ans;
    }
};