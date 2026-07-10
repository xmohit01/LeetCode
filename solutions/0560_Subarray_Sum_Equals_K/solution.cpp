class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> preSum(n, 0); preSum[0] = nums[0];

        for(int i = 1; i < n; i++)
            preSum[i] = preSum[i - 1] + nums[i];
        
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            if(preSum[i] == k) count++;

            int val = preSum[i] - k;
            if(m.find(val) != m.end()) count += m[val];
            m[preSum[i]]++;
        }

        return count;
    }
};                                               