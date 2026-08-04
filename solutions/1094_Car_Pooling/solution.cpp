class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stops(1001, 0);
        
        for(auto& trip : trips){
            stops[trip[1]] += trip[0];
            stops[trip[2]] -= trip[0];
        }

        int curr_pess = 0;
        for(int i = 0; i <= 1000; i++){
            curr_pess += stops[i];

            if(curr_pess > capacity) return false;
        }

        return true;
    }
};