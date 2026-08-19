class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> m;

        for(auto& reservedSeat : reservedSeats) m[reservedSeat[0]].push_back(reservedSeat[1]);

        int ans = 2 * (n - m.size());

        for(auto& p : m){
            bool combination1 = true;
            bool combination2 = true;
            bool combination3 = true;

            for(int seat : p.second){
                if(seat >= 2 && seat <= 5) combination1 = false;
                if(seat >= 4 && seat <= 7) combination2 = false;
                if(seat >= 6 && seat <= 9) combination3 = false;
            }
            if(combination1 && combination3) ans += 2;

            else if(combination1 || combination2 || combination3) ans++;
        }
        return ans;
    }
};