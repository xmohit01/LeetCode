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
    int maxDepth(TreeNode* root, unordered_map<int, int>& m) {
        if(root == NULL) return 0;

        int leftH = maxDepth(root->left, m);
        int rightH = maxDepth(root->right, m);

        m[root->val] = 1 + max(leftH, rightH);

        return m[root->val];
    }
    void helper(TreeNode* root, unordered_map<int, int>& m, int maxDepth, int depth, unordered_map<int, int>& ansMap) {
        if(root == NULL) return;

        ansMap[root->val] = maxDepth;

        // for left child
        int rightMax = max(maxDepth, depth);
        if(root->right != NULL)
            rightMax = max(rightMax, depth + m[root->right->val]);

        int leftMax = max(maxDepth, depth);
        if(root->left != NULL)
            leftMax = max(leftMax, depth + m[root->left->val]);

        helper(root->left, m, rightMax, depth + 1, ansMap);

        helper(root->right, m, leftMax, depth + 1, ansMap);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = queries.size();

        unordered_map<int, int> ansMap;

        unordered_map<int, int> m;

        maxDepth(root, m);
        
        helper(root, m, 0, 0, ansMap);

        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            result[i] = ansMap[queries[i]];
        }

        return result;
    }
};