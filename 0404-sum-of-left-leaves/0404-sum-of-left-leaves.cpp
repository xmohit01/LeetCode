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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = 0;
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* currNode = q.front();
                q.pop();

                if(currNode->left != NULL){
                    if(currNode->left->left == NULL && currNode->left->right == NULL) ans += currNode->left->val;

                    else q.push(currNode->left);
                }
                if(currNode->right != NULL) q.push(currNode->right);
            }
        }

        return ans;
    }
};