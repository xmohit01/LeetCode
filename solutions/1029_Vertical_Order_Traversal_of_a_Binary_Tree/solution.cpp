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
    void helper(TreeNode* root, map<int, map<int, multiset<int>>> &mms, int col, int row){
        if(root == NULL) return;

        mms[col][row].insert(root->val);

        helper(root->left, mms, col - 1, row + 1);
        helper(root->right, mms, col + 1, row + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mms;

        helper(root, mms, 0, 0);

        vector<vector<int>> ans;
        for(auto p : mms){
            vector<int> current_column;
            for(auto ms : p.second){
                for(auto val : ms.second){
                    current_column.push_back(val);
                }
            }
            ans.push_back(current_column);
        }

        return ans;
    }
};