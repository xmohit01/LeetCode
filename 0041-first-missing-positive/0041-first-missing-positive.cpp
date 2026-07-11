class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        while(i < n && nums[i] <= 0) i++;
        if(i == n) return 1;

        int help = 1;
        for(i; i < n; i++){
            while(i > 0 && i < n && nums[i] == nums[i - 1]) i++;

            if(i < n && nums[i] != help){
                return help;
            }
            else if(i < n) help++;        
        }
        return help;
    }
};