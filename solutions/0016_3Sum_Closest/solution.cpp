class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int checker = INT_MAX, ans;
        for(int i = 0; i < n; i++){
            int j = i + 1, k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum - target == 0) return target;
                else if(sum > target){
                    k--;
                    if(checker > sum - target){
                        ans = sum;
                        checker = sum - target;
                    }
                }
                else{
                    j++;
                    if(checker > target - sum){
                        ans = sum;
                        checker = target - sum;
                    }
                }
            }
        }
        return ans;
    }
};