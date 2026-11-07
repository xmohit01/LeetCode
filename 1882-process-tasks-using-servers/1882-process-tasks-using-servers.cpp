class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // Free Servser : {Weight, Index}.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;

        // Busy Servers : {Free Time, Weight, Index}.
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busyServers;

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> res(m);

        for(int i = 0; i < m; i++) {
            // Try to move busy servers to free servers if they can at this time.
            while(!busyServers.empty() && get<0>(busyServers.top()) <= i) {
                auto [freeTime, weight, idx] = busyServers.top();

                busyServers.pop();

                freeServers.push({weight, idx});
            }

            if(freeServers.empty()) {
                auto [freeTime, weight, idx] = busyServers.top();

                busyServers.pop();

                res[i] = idx;

                busyServers.push({freeTime + tasks[i], weight, idx});
            }
            else {
                auto p = freeServers.top();

                freeServers.pop();

                res[i] = p.second;

                busyServers.push({i + tasks[i], p.first, p.second});
            }
        }

        return res;
    }
};