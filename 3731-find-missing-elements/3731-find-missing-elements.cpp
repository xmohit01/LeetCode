class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.empty()) return {};

        sort(nums.begin(), nums.end());
        vector<int> ans;

        int st = 0, end = nums.size() - 1;
        for(int i = 1; i < nums.size(); i++){
            int expected = nums[i - 1] + 1;

            while(expected < nums[i]){
                ans.push_back(expected);
                expected++;
            }
        }
        return ans;
    }
};