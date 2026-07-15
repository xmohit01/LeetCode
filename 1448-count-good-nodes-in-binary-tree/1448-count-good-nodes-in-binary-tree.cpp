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

    void helper(TreeNode* root, int max_so_far, int &ans){
        if(root == NULL) return;

        max_so_far = max(max_so_far, root->val);
        if(max_so_far == root->val) ans++;

        helper(root->left, max_so_far, ans);
        helper(root->right, max_so_far, ans);
    }

    int goodNodes(TreeNode* root) {
        int ans = 0;
        int maxx = INT_MIN;

        helper(root, maxx, ans);
        return ans;
    }
};