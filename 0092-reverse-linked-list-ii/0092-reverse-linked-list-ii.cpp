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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for(int i = 0; i < left - 1; i++) prev = prev->next;

        ListNode* curr = prev->next;
        ListNode* nextNode = NULL;
        ListNode* reversePrev = NULL;

        for(int i = 0; i <= right - left; i++){
            nextNode = curr->next;
            curr->next = reversePrev;
            reversePrev = curr;
            curr = nextNode;
        }

        prev->next->next = curr; 
        prev->next = reversePrev;

        return dummy->next;
    }
};