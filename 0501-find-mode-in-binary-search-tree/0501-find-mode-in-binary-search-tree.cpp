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
    int prev = INT_MAX;
    int freq = 0, maxFreq = 0;
    bool first = true;

    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root->left);

        if(first || root->val != prev) {
            freq = 1;
            prev = root->val;
            first = false;
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