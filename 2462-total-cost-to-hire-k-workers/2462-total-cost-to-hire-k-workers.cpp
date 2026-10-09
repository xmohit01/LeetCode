class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        long long cost = 0;

        int st = 0, end = n - 1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int l = 0, r = n - 1;

        for(int i = 0; i < candidates && l <= r; i++) {
            pq.push({costs[l], l});
            l++;
        }

        for(int i = 0; i < candidates && l <= r; i++) {
            pq.push({costs[r], r});
            r--;
        }

        for(int session = 0; session < k; session++) {
            auto p = pq.top();
            pq.pop();

            cost += p.first;

            if(l <= r) {
                if(p.second < l) {
                    pq.push({costs[l], l});
                    l++;
                }
                else {
                    pq.push({costs[r], r});
                    r--;
                }
            }
        }

        return cost;
    }
};