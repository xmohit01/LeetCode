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
    bool helper(TreeNode* root, long long MAXX, long long MINN){
        if(root == NULL) return true;

        if(root->val >= MAXX || root->val <= MINN) return false;

        bool leftCheck = helper(root->left, root->val, MINN);
        bool rightCheck = helper(root->right, MAXX, root->val);

        return leftCheck && rightCheck;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MAX, LONG_MIN);
    }
};