class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for(auto& booking : bookings){
            int stIdx = booking[0] - 1;
            int endIdx = booking[1] - 1;
            
            ans[stIdx] += booking[2];
            if(endIdx < n - 1) ans[endIdx + 1] -= booking[2];
        }
        for(int i = 1; i < n; i++) ans[i] += ans[i - 1];
        
        return ans;
    }
};