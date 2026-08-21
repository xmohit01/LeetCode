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
    int helper(TreeNode* root){
        if(root == NULL) return 0;

        int leftCheck = helper(root->left);
        int leftSize = 0;
        if(root->left != NULL && root->left->val == root->val) leftSize = leftCheck + 1;
        
        int rightCheck = helper(root->right);
        int rightSize = 0;
        if(root->right != NULL && root->right->val == root->val) rightSize = rightCheck + 1;

        ans = max(ans, leftSize + rightSize);

        return max(leftSize, rightSize);
    }

    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ans;
    }
};