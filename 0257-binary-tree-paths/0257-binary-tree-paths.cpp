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

    void helper(TreeNode* root, string s, vector<string>& ans){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(s);
            return;
        }

        if(root->left != NULL){
            helper(root->left, (s + "->" + to_string(root->left->val)), ans);
        }
        if(root->right != NULL){
            helper(root->right, (s + "->" + to_string(root->right->val)), ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = to_string(root->val);
        helper(root, s, ans);
        return ans;
    }
};