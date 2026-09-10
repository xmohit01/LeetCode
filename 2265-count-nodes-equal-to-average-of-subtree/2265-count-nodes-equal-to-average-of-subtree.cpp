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
    pair<int, int> helper(TreeNode* root){
        if(root == NULL) return {0, 0};

        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);

        int leftSum = left.first;
        int rightSum = right.first;

        int leftNodes = left.second;
        int rightNodes = right.second;

        int subtreeSum = leftSum + rightSum + root->val;
        int nodes = leftNodes + rightNodes + 1;

        if((subtreeSum / nodes) == root->val) ans++;

        return {subtreeSum, nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        helper(root);

        return ans;
    }
};