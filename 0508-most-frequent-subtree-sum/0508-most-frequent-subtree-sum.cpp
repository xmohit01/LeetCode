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
    int maxFreq = 0;
    int helper(TreeNode* root, unordered_map<int, int>& m){
        if(root == NULL) return 0;

        int leftSum = helper(root->left, m);
        int rightSum = helper(root->right, m);

        int totalSum = root->val + leftSum + rightSum;
        m[totalSum]++;
        maxFreq = max(maxFreq, m[totalSum]);

        return totalSum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        helper(root,  m);

        vector<int> ans;
        for(auto& p : m){
            if(p.second == maxFreq) ans.push_back(p.first);
        }
        return ans;
    }
};