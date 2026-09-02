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
    vector<TreeNode*> ans;
    TreeNode* deleteKr(TreeNode* root, unordered_set<int>& toDelete){
        if(root == NULL) return NULL;

        root->left = deleteKr(root->left, toDelete);
        root->right = deleteKr(root->right, toDelete);

        if(toDelete.count(root->val)){
            if(root->left != NULL) ans.push_back(root->left);
            if(root->right != NULL) ans.push_back(root->right);

            return NULL;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());

        root = deleteKr(root, toDelete);
        if(root != NULL) ans.push_back(root);

        return ans;
    }
};