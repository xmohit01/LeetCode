class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<pair<int, int>> v;
        unordered_map<int, vector<int>> m;

        // Prefix sum 0 exists before the array starts
        m[0].push_back(-1);

        int prefix = 0;

        for(int i = 0; i < n; i++){
            prefix += arr[i];

            // Need an earlier prefix = prefix - target
            int temp = prefix - target;

            if(m.count(temp)){
                // Every matching prefix gives a subarray with sum = target
                for(int t : m[temp]) v.push_back({t + 1, i});
            }

            m[prefix].push_back(i);
        }

        // shortest[i] = shortest valid subarray ending exactly at i
        vector<int> shortest(n, INT_MAX);
        for(auto& p : v){
            int len = p.second - p.first + 1;

            shortest[p.second] = min(shortest[p.second], len);
        }

        // Make shortest[i] = shortest valid subarray ending at or before i
        for(int i = 1; i < n; i++){
            shortest[i] = min(shortest[i], shortest[i - 1]);
        }

        int ans = INT_MAX;
        for(auto p : v){
            int l = p.first;
            int r = p.second;

            int len = r - l + 1;

            // shortest[l-1] guarantees the previous subarray doesn't overlap
            if(l > 0 && shortest[l - 1] != INT_MAX){
                ans = min(ans, len + shortest[l - 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};