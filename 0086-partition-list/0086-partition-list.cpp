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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prev = NULL;
        ListNode* firstGreaterX = head;
        ListNode* newHead = head;

        while(firstGreaterX != NULL && firstGreaterX->val < x){
            prev = firstGreaterX;
            firstGreaterX = firstGreaterX->next;
        }

        if(firstGreaterX == NULL) return head;

        ListNode* temp = firstGreaterX->next;
        ListNode* reserve = firstGreaterX;

        while(temp != NULL){
            if(temp->val < x){
                if(prev != NULL){
                    prev->next = temp;
                    prev = temp;
                }
                else{
                    prev = temp;
                    newHead = prev;
                }
            }
            else{
                firstGreaterX->next = temp;
                firstGreaterX = temp;
            }
            temp = temp->next;
        }
        
        if(prev != NULL) prev->next = reserve;
        firstGreaterX->next = NULL;

        return newHead;
    }
};