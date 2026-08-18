class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int& num : nums) freq[num]++;

        if(n == k){
            return *max_element(nums.begin(), nums.end());
        }

        else if(k == 1){
            int ans = -1;

            for(auto& p : freq){
                if(p.second == 1) ans = max(ans, p.first);
            }
            return ans;
        }

        int ans = -1;
        if(freq[nums[0]] == 1) ans = max(ans, nums[0]);
        if(freq[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);

        return ans;
    }
};