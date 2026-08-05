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
class Solution {
public:
    ListNode* helper(vector<ListNode*>& lists){
        int mini = INT_MAX;
        int idx = -1;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != NULL && lists[i]->val < mini){
                mini = lists[i]->val;
                idx = i;
            }
        }

        if(idx == -1) return NULL;

        lists[idx] = lists[idx]->next;
        ListNode* newNode = new ListNode(mini);
        newNode->next = helper(lists);
        return newNode;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return helper(lists);
    }
};