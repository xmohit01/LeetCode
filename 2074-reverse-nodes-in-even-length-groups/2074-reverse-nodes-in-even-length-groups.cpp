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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        int nodes = 0;
        while(curr != NULL){
            nodes++;
            curr = curr->next;
        }
        curr = head;

        int size = 1;

        while(curr != NULL){
            int actualLength = min(size, nodes);

            if(actualLength % 2 == 1){
                for(int i = 0; i < actualLength && curr != NULL; i++){
                    prev = curr;
                    curr = curr->next;
                }
            }
            else{
                ListNode* prevLast = prev;
                ListNode* prevCurr = curr;
                for(int i = 0; i < actualLength && curr != NULL; i++){
                    next = curr->next;
                    curr->next = prev;

                    prev = curr;
                    curr = next;
                }
                if(prevCurr != NULL)
                    prevCurr->next = curr;
                if(prevLast != NULL)
                    prevLast->next = prev;

                prev = prevCurr;
            }
            nodes -= size;
            size++;
        }
        return head;
    }
};