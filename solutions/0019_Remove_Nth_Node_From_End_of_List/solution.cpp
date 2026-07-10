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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* last_sec = NULL;
        int length = 1;
        while(temp->next != NULL){
            length++;
            last_sec = temp;
            temp = temp->next;
        }

        if(n == length){
            head = head->next;
            return head;
        }

        if(n == 1){
            last_sec->next = NULL;
            return head;
        }

        int k = length - n + 1;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(k-- != 1){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        return head;
    }
};