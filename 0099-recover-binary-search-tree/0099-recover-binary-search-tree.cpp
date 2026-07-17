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
    TreeNode* wrong1 = NULL;
    TreeNode* wrong2 = NULL;
    void helper(TreeNode* root){
        if(root == NULL) return;

        helper(root->left);
        if(prevNode != NULL){
            if(prevNode->val > root->val){
                if(wrong1 == NULL){
                    wrong1 = prevNode;
                    wrong2 = root;
                }
                else wrong2 = root;
            }
        }
        prevNode = root;
        helper(root->right);
    }

    void recoverTree(TreeNode* root) {
        helper(root);
        swap(wrong1->val, wrong2->val);
    }
};