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
    // Calculate the height of every node's subtree
    int maxDepth(TreeNode* root, unordered_map<int, int>& m) {
        if(root == NULL) return 0;

        int leftH = maxDepth(root->left, m);
        int rightH = maxDepth(root->right, m);

        // Store subtree height in number of nodes
        m[root->val] = 1 + max(leftH, rightH);

        return m[root->val];
    }
    void helper(TreeNode* root, unordered_map<int, int>& m, int maxDepth, int depth, unordered_map<int, int>& ansMap) {
        if(root == NULL) return;

        // Store the height remaining outside this node's subtree
        ansMap[root->val] = maxDepth;

        // Calculate the maximum depth to pass to the left child
        int rightMax = max(maxDepth, depth);
        if(root->right != NULL) // Consider the deepest node in the right sibling's subtree
            rightMax = max(rightMax, depth + m[root->right->val]);

        // Calculate the maximum depth to pass to the right child
        int leftMax = max(maxDepth, depth);
        if(root->left != NULL) // Consider the deepest node in the left sibling's subtree
            leftMax = max(leftMax, depth + m[root->left->val]);

        // Process the left and right subtrees
        helper(root->left, m, rightMax, depth + 1, ansMap);

        helper(root->right, m, leftMax, depth + 1, ansMap);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int n = queries.size();

        unordered_map<int, int> ansMap;

        unordered_map<int, int> m;

        // First DFS: calculate every node's subtree height
        maxDepth(root, m);
        
        // Second DFS: calculate the answer for removing each node's subtree
        helper(root, m, 0, 0, ansMap);

        vector<int> result(n);
        // Put} answers in the order of the given queries
        for(int i = 0; i < n; i++) {
            result[i] = ansMap[queries[i]];
        }

        return result;
    }
};