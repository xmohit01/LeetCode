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

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int max_width = 0;
        while(q.size() > 0){
            int curr_size = q.size();
            long long stIdx = q.front().second;
            long long endIdx = q.back().second;

            max_width = max(max_width, (int)(endIdx - stIdx + 1));

            for(int i = 0; i < curr_size; i++){
                auto currPair = q.front();
                TreeNode* currNode = currPair.first;
                long long currIdx = currPair.second - stIdx;
                q.pop();

                if(currNode->left != NULL){
                    q.push({currNode->left, 2 * currIdx + 1});
                }
                if(currNode->right != NULL){
                    q.push({currNode->right, 2 * currIdx + 2});
                }
            }
        }
        return max_width;
    }
};