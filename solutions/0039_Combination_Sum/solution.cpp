class Solution {
public:

    void helper(vector<int>& candidates, int idx, int target, vector<int> &combi, vector<vector<int>> &ans){

        if(idx == candidates.size() || target < 0) return;
        if(target == 0){
            if(find(ans.begin(), ans.end(), combi) == ans.end()){
            ans.push_back(combi);
            }
            return;
        }


        combi.push_back(candidates[idx]);
        helper(candidates, idx + 1, target - candidates[idx], combi, ans);
        helper(candidates, idx, target - candidates[idx], combi, ans);
        combi.pop_back();
        helper(candidates, idx + 1, target, combi, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combi;

        helper(candidates, 0, target, combi, ans);

        return ans;
    }
};