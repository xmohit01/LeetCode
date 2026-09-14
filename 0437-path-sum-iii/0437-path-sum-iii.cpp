/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void helper(TreeNode* root, int targetSum, long long currSum, unordered_map<long long, int>& m){
        if(root == NULL) return;

        currSum += root->val;

        long long val = currSum - targetSum;

        if(m.find(val) != m.end()) ans += m[val];

        m[currSum]++;
        helper(root->left, targetSum, currSum, m);
        helper(root->right, targetSum, currSum, m);
        m[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> m;
        m[0] = 1;

        helper(root, targetSum, 0, m);
        return ans;
    }
};