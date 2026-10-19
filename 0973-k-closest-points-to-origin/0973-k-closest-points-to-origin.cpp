class Solution {
public:
    double dist(int& x, int& y) {
        return sqrt(x * x + y * y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, vector<int>>> v;

        for(auto& point : points) {
            v.push_back({dist(point[0], point[1]), point});
        }

        sort(v.begin(), v.end());

        vector<vector<int>> ans;
        for(int i = 0; i < k; i++) ans.push_back(v[i].second);

        return ans;
    }
};