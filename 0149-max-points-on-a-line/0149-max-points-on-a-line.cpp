class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        int maxPointsInLine = 0;

        for(int i = 0; i < n; i++){
            unordered_map<double, int> m;

            for(int j = i + 1; j < n; j++){
                double neu = points[i][1] - points[j][1];
                double den = points[i][0] - points[j][0];

                double slope = den == 0 ? 1e9 : neu / den;

                m[slope]++;
                maxPointsInLine = max(maxPointsInLine, m[slope]);
            }
        }
        return maxPointsInLine + 1;
    }
};