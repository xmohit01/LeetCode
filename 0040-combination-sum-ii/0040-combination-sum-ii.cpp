class Solution {
public:
    void helper(vector<int>& candidates, int idx, int target, vector<int> &combi, vector<vector<int>> &ans){

        if (target == 0) {
            ans.push_back(combi);
            return;
        }

        for(int i = idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            combi.push_back(candidates[i]);
            helper(candidates, i + 1, target - candidates[i], combi, ans);
            combi.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combi;

        helper(candidates, 0, target, combi, ans);

        sort(ans.begin(), ans.end());
        return ans;
    }
};