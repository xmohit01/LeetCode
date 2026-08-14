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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            int sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* currNode = q.front();
                q.pop();

                sum += currNode->val;
                if(currNode->left != NULL) q.push(currNode->left);
                if(currNode->right != NULL) q.push(currNode->right);
            }

            if(q.empty()) return sum;
        }
        return -1;
    }
};