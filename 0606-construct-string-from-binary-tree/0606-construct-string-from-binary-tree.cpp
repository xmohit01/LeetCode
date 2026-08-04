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
    void builder(TreeNode* root, string& str){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            str += to_string(root->val);
            return;
        }

        str += to_string(root->val);

        if(root->left != NULL || root->right != NULL){
            str += '(';
            builder(root->left, str);
            str += ")";
        }

        if(root->right != NULL){
            str += "(";
            builder(root->right, str);
            str += ')';
        }
    }

    string tree2str(TreeNode* root) {
        string ans = "";
        builder(root, ans);
        return ans;
    }
};