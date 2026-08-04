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
    void helper(TreeNode* root, vector<int>& vec){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL) vec.push_back(root->val);

        helper(root->left, vec);
        helper(root->right, vec);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;

        helper(root1, ans1);
        helper(root2, ans2);

        return ans1 == ans2;
    }
};