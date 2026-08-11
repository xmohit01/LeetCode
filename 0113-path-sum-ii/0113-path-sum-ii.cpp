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
    void helper(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& vec){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL){
            if(targetSum == root->val){
                vec.push_back(root->val);
                ans.push_back(vec);
                vec.pop_back();
                return;
            }
        }

        if(root->left != NULL){
            vec.push_back(root->val);
            helper(root->left, targetSum - root->val, ans, vec);
            vec.pop_back();
        }
        if(root->right != NULL){
            vec.push_back(root->val);
            helper(root->right, targetSum - root->val, ans, vec);
            vec.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;

        vector<int> vec;
        helper(root, targetSum, ans, vec);

        return ans;
    }
};