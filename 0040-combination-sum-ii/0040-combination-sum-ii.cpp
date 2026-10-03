class Solution {
public:
    void helper(vector<int>& candidates, int idx, int target, vector<int> &combi, vector<vector<int>> &ans){
        if (target == 0) {
            ans.push_back(combi);
            return;
        }

        if(idx >= candidates.size() || target < 0) return;

        combi.push_back(candidates[idx]);
        helper(candidates, idx + 1, target - candidates[idx], combi, ans);
        combi.pop_back();

        int next = idx + 1;

        while(next < candidates.size() && candidates[next] == candidates[idx]) {
            next++;
        }

        helper(candidates, next, target, combi, ans);
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