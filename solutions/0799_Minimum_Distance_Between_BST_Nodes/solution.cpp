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
    TreeNode* prevNode = NULL;
    int minDiff = INT_MAX;

    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if(prevNode != NULL) minDiff = min(minDiff, root->val - prevNode->val);

        prevNode = root;

        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);

        return minDiff;
    }
};