class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int ans = 1, temp = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                if(nums[i] - nums[i - 1] != 1){
                    temp = 1;
                }
                else{
                    temp++;
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};