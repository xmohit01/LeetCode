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
    int ans = INT_MIN;
    int helper(TreeNode* root, int prevMove, int currSize){
        if(root == NULL){
            ans = max(ans, currSize);
            return currSize;
        }
        if(prevMove == 1){
            ans = max(ans, currSize);
            int continuing = helper(root->left, 0, currSize + 1);
            int starting = helper(root->right, 1, 1);

            return max(continuing, starting);
        }

        else{
            ans = max(ans, currSize);
            int continuing = helper(root->right, 1, currSize + 1);
            int starting = helper(root->left, 0, 1);

            return max(continuing, starting);
        }
    }
    int longestZigZag(TreeNode* root) {
        helper(root, 0, 0);  // 0 means prev left
        helper(root, 1, 0);  // 1 means prev right

        return ans - 1;
    }
};