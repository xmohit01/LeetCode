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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root == NULL){
            return new TreeNode(val);
        }
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;

            return newNode;
        }

        int currDepth = 1;
        queue<TreeNode*> q;
        q.push(root);

        while(currDepth < depth - 1){
            int size = q.size();

            for(int i = 0; i < size; i++){
                TreeNode* currNode = q.front();
                q.pop();

                if(currNode->left != NULL) q.push(currNode->left);
                if(currNode->right != NULL) q.push(currNode->right);
            }
            currDepth++;
        }

        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();

            TreeNode* oldLeft = currNode->left;
            TreeNode* oldRight = currNode->right;

            currNode->left = new TreeNode(val);
            currNode->right = new TreeNode(val);

            currNode->left->left = oldLeft;
            currNode->right->right = oldRight;
        }
        return root;
    }
};