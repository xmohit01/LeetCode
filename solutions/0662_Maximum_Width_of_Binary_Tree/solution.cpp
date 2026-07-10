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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long long ans = 1;

        while(!q.empty()){
            int size = q.size();
            long long idx_1 = q.front().second;
            long long idx_2 = idx_1;

            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();

                TreeNode* curr_node = curr.first;
                long long width = curr.second - idx_1;

                if(i == size - 1) idx_2 = width;

                if(curr_node->left != NULL) q.push({curr_node->left, 2 * width});
                if(curr_node->right != NULL) q.push({curr_node->right, 2 * width + 1});
            }
            ans = max(ans, idx_2 + 1);
        }
        return ans;
    }
};