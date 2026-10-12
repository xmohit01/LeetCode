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
    vector<int> ans;
    int prev = 0;
    int freq = 0, maxFreq = 0;

    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root->left);

        if(root->val != prev) {
            freq = 1;
            prev = root->val;
        }
        else {
            freq++;
        }

        if(freq > maxFreq) {
            maxFreq = freq;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(freq == maxFreq) {
            ans.push_back(root->val);
        }

        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);

        return ans;
    }
};