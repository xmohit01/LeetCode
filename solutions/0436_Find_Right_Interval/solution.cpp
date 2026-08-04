class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> starts;
        for(int i = 0; i < n; i++){
            starts.push_back({intervals[i][0], i});
        }

        sort(starts.begin(), starts.end());

        vector<int> ans;
        for(int i = 0; i < n; i++){
            int lowestStart = intervals[i][1];
            
            int st = 0, end = n - 1, temp = -1;
            while(st <= end){
                int mid = st + (end - st) / 2;

                if(starts[mid].first >= lowestStart){
                    temp = starts[mid].second;
                    end = mid - 1;
                }
                else st = mid + 1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};