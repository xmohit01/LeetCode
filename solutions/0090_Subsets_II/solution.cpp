class Solution {
public:
    void allSubsets(vector<int> &nums, vector<vector<int>> &ans, vector<int> subsets, int i){
        if(i == nums.size()){
            ans.push_back({subsets});
            
            return;
        }

        vector<int> temp;
        subsets.push_back(nums[i]);
        allSubsets(nums, ans, subsets, i + 1);

        subsets.pop_back();
        
        int idx = i + 1;
        while(idx < nums.size() && nums[idx] == nums[i]) idx++;

        allSubsets(nums, ans, subsets, idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subsets;
        allSubsets(nums, ans, subsets, 0);
        
        return ans;
    }
};