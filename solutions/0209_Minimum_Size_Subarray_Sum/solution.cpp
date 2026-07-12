class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        queue<int> q;
        int ans = INT_MAX, count = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= target) return 1;
            q.push(nums[i]);
            sum += nums[i];
            count++;

            if(sum >= target){
                while(sum >= target){
                    ans = min(ans, count);

                    sum -= q.front();
                    q.pop();
                    count--;
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};