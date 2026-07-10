class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prev = 0, ans = 0;

        for(int i = 0; i < gain.size(); i++){
            int temp = gain[i] + prev;

            ans = max(ans, temp);

            prev += gain[i];
        }

        return ans;
    }
};