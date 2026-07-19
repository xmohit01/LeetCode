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
    int helper(TreeNode* root, int& ans){
        if(root -> left == NULL && root->right == NULL){
            ans += 1;
            return root->val;
        }

        int leftMax = 0;
        if(root->left != NULL)leftMax = helper(root->left, ans);
        int rightMax = 0;
        if(root->right != NULL) rightMax = helper(root->right, ans);

        if(root->val >= leftMax && root->val >= rightMax) ans += 1;

        return max({leftMax, rightMax, root->val});
    }
    
    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        int maxx = helper(root, ans);

        return ans;
    }
};