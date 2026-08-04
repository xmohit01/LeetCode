class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double sum = 0;
        double ans = INT_MIN;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        ans = sum / k;

        for(int i = k; i < n; i++){
            sum += nums[i];
            sum -= nums[i - k];

            ans = max(ans, (sum / k));
        }
        return ans;
    }
};