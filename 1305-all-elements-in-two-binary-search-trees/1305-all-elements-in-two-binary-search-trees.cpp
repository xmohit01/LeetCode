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
    void treeToVec(TreeNode* root, vector<int>& result){
        if(root == NULL) return;

        treeToVec(root->left, result);
        result.push_back(root->val);
        treeToVec(root->right, result);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1;
        vector<int> vec2;
        vector<int> ans;

        treeToVec(root1, vec1);
        treeToVec(root2, vec2);

        int i = 0;
        int j = 0;

        while(i < vec1.size() && j < vec2.size()){
            if(vec1[i] < vec2[j]) ans.push_back(vec1[i++]);
            
            else ans.push_back(vec2[j++]);
        }
        while(i < vec1.size()) ans.push_back(vec1[i++]);
        while(j < vec2.size()) ans.push_back(vec2[j++]);

        return ans;
    }
};