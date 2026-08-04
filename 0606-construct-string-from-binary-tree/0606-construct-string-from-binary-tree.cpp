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
    void builder(TreeNode* root, string& str){
        if(root == NULL){   // if null ofcourse we have to return
            return;
        }

        if(root->left == NULL && root->right == NULL){   // if both are NULL then we just have to add value bcoz the brackets are already taken care at our calling area!!!
            str += to_string(root->val);
            return;
        }

        str += to_string(root->val);  // adding the current value

        if(root->left != NULL || root->right != NULL){    // if left exists then ofcourse we have to add than value in brackets and if left does'nt exist but right exist then we should add empty brackets for that we will call it!!
            str += '(';
            builder(root->left, str);
            str += ")";
        }

        if(root->right != NULL){    // ofcourse rigth will add if it will exist..
            str += "(";
            builder(root->right, str);
            str += ')';
        }
    }

    string tree2str(TreeNode* root) {
        string ans = "";
        builder(root, ans);
        return ans;
    }
};