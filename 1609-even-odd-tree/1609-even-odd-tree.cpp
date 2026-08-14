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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int currLevel = 0;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* currNode = q.front();
                q.pop();

                if(currLevel % 2 == 0){
                    if(currNode->val % 2 == 0) return false;
                }
                else{
                    if(currNode->val % 2 == 1) return false;
                }

                if(i != size - 1){
                    TreeNode* nextNode = q.front();

                    if(currLevel % 2 == 0){
                        if(currNode->val >= nextNode->val) return false;
                    }
                    else{
                        if(currNode->val <= nextNode->val) return false;
                    }
                }                

                if(currNode->left != NULL) q.push(currNode->left);
                if(currNode->right != NULL) q.push(currNode->right);
            }
            currLevel++;
        }
        return true;
    }
};