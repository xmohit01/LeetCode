class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> m;
        int ans = -1;
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }
        for(auto& p : m){
            if(p.first == p.second) ans = max(ans, p.first);
        }
        return ans;
    }
};