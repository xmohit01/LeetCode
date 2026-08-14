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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if(root == NULL) return new TreeNode(val);

        // if(root->val > val) root->left = insertIntoBST(root->left, val);
        // else root->right =  insertIntoBST(root->right, val);

        // return root;

        if(root == NULL) return new TreeNode(val);

        TreeNode* currNode = root;

        while(true){
            if(currNode->val > val){
                if(currNode->left != NULL) currNode = currNode->left;
                else{
                    currNode->left = new TreeNode(val);;
                    break;
                }
            }
            else{
                if(currNode->right != NULL) currNode = currNode->right;
                else{
                    currNode->right = new TreeNode(val);;
                    break;
                }
            }
        }
        return root;
    }
};