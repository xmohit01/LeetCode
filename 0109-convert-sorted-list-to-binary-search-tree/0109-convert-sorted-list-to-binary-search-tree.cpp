/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* helper(vector<int>& temp, int st, int end){
        if(end < st) return NULL;

        int mid = st + (end - st) / 2;

        TreeNode* newNode = new TreeNode(temp[mid]);

        newNode->left = helper(temp, st, mid - 1);
        newNode->right = helper(temp, mid + 1, end);

        return newNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;

        vector<int> temp;
        while(head != NULL){
            temp.push_back(head->val);

            head = head->next;
        }

        int st = 0, end = temp.size() - 1;

        return helper(temp, st, end);
    }
};