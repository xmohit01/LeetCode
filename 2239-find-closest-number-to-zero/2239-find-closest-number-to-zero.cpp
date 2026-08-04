class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans, diff = INT_MAX;
        for(int num : nums){
            if(abs(num) < diff){
                diff = abs(num);
                ans = num;
            }
            else if(abs(num) == diff) ans = max(ans, num);
        }
        return ans;
    }
};