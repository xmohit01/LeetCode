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
    int ans;

    void helper(TreeNode* root, int k, int& present){
        if(root == NULL) return;

        helper(root->left, k, present);
        if(present == k){
            ans = root->val;
        }
        present++;
        helper(root->right, k, present);
    }

    int kthSmallest(TreeNode* root, int k) {
        int present = 1;
        helper(root, k, present);
        return ans;
    }
};