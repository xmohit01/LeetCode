class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int prevSum = 0;
        
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            prevSum += nums[i];

            if(prevSum == k) count++;

            int val = prevSum - k;
            if(m.find(val) != m.end()) count += m[val];
            m[prevSum]++;
        }

        return count;
    }
};