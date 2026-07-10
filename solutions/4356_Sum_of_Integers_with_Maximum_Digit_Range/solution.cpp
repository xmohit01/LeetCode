class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        int max_range = -1;
        for(int i = 0; i < n; i++){
            int max_dig = 0, min_dig = 9;
            int temp = abs(nums[i]);
            if(temp == 0){
                max_dig = max(max_dig, 0);
                min_dig = min(min_dig, 0);
            }
            while(temp > 0){
                int dig = temp % 10;
                max_dig = max(max_dig, dig);
                min_dig = min(min_dig, dig);
                temp /= 10;
            }
            max_range = max(max_range, max_dig - min_dig);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int max_dig = 0, min_dig = 9;
            int temp = abs(nums[i]);
            if(temp == 0){
                max_dig = max(max_dig, 0);
                min_dig = min(min_dig, 0);
            }
            while(temp > 0){
                int dig = temp % 10;
                max_dig = max(max_dig, dig);
                min_dig = min(min_dig, dig);
                temp /= 10;
            }
            if(max_dig - min_dig == max_range){
                ans += nums[i];
            }
        }
        return ans;
    }
};