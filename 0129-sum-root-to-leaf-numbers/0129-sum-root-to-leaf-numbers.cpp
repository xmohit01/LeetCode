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
    void helper(TreeNode* root, int temp){
        if(root == NULL) return;
        temp = temp * 10 + root->val;

        if(root->left == NULL && root->right == NULL){
            ans += temp;
        }
        helper(root->left, temp);
        helper(root->right, temp);
    }

    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return ans;
    }
};