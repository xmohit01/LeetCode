class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1;

        sort(points.begin(), points.end());

        int n = points.size();

        int lastEnd = points[0][1];

        for(int i = 1; i < n; i++){
            if(lastEnd >= points[i][0]) {
                lastEnd = min(lastEnd, points[i][1]);
            }
            else {
                lastEnd = points[i][1];
                count++;
            }
        }

        return count;
    }
};