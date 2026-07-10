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

    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(root == NULL || subRoot == NULL) return root == subRoot;

        if(root->val != subRoot->val) return false;

        return isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;

        if(root->val == subRoot->val && isIdentical(root, subRoot)) return true;

        bool leftCheck = isSubtree(root->left, subRoot);
        bool rightCheck = isSubtree(root->right, subRoot);

        return leftCheck || rightCheck;
    }
};