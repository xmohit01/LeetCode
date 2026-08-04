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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int size = 0;
        while(head != NULL){
            size++;
            head = head->next;
        }

        k %= size;
        head = dummy->next;

        ListNode* next;
        int currVal = head->val, prevVal;
        while(k--){
            while(head->next != NULL){
                prevVal = currVal;
                head = head->next;
                currVal = head->val;
                head->val = prevVal;
            }
            head = dummy->next;
            head->val = currVal;
        }
        return dummy->next;
    }
};