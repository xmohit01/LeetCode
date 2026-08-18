class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        for(int i = 0; i <= n - k; i++){
            unordered_set<int> window(nums.begin() + i, nums.begin() + i + k);

            for(auto& val : window){
                m[val]++;
            }
        }

        int ans = -1;
        for(auto& p : m){
            if(p.second == 1) ans = max(ans, p.first);
        }

        return ans;
    }
};