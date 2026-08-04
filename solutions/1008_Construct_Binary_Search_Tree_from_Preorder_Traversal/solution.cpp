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
    int idx = 0;

    TreeNode* build(vector<int>& preorder, int upper_bound){
        if(idx >= preorder.size() || preorder[idx] >= upper_bound) return NULL;

        TreeNode* newNode = new TreeNode(preorder[idx]);
        idx++;

        newNode->left = build(preorder, newNode->val);
        newNode->right = build(preorder, upper_bound);

        return newNode;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};