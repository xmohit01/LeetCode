class Solution {
public:
    void allSubsets(vector<int> &nums, vector<vector<int>> &ans, vector<int> subsets, int i){
        if(i == nums.size()){
            ans.push_back({subsets});
            
            return;
        }

        vector<int> temp;
        subsets.push_back(nums[i]); allSubsets(nums, ans, subsets, i + 1);
        subsets.pop_back(); allSubsets(nums, ans, subsets, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        allSubsets(nums, ans, subset, 0);

        return ans;
    }
};