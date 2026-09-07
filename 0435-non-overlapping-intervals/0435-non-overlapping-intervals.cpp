class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;

        int count = 0;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        int lastEnd = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(lastEnd > intervals[i][0]){
                lastEnd = min(lastEnd, intervals[i][1]);
                count++;
            }
            else{
                lastEnd = intervals[i][1];
            }
        }
        return count;
    }
};