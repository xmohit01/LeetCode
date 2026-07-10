class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }

        int ans = 0;
        for(auto pair : m){
            if(pair.second == 1) ans += pair.first;
        }

        return ans;
    }
};