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
    int minSwaps(vector<int>& arr){
        int n = arr.size();
        vector<pair<int,int>> v(n);

        for(int i = 0; i < n; i++) v[i] = {arr[i], i};

        sort(v.begin(), v.end());

        vector<bool> vis(n, false);
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(vis[i] || v[i].second == i)
                continue;

            int j = i, cycle = 0;

            while(!vis[j]){
                vis[j] = true;
                j = v[j].second;
                cycle++;
            }

            ans += cycle - 1;
        }

        return ans;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;

            for(int i = 0; i < size; i++){
                TreeNode* currNode = q.front();
                q.pop();

                temp.push_back(currNode->val);
                if(currNode->left != NULL) q.push(currNode->left);
                if(currNode->right != NULL) q.push(currNode->right);
            }
            ans += minSwaps(temp);
        }
        return ans;
    }
};