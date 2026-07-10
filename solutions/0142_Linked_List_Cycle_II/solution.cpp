/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowptr = head;
        ListNode* fastptr = head;

        bool cycle = false;

        while(fastptr != NULL && fastptr->next != NULL){
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;

            if(slowptr == fastptr) {cycle = true; break;}
        }

        if(!cycle) return NULL;

        slowptr = head;
        while(slowptr != fastptr){
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }
        return slowptr;
    }
};