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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        head = head->next;
        int summ = 0;
        while(head != NULL){
            if(head->val == 0){
                head = head->next;
                ListNode* newNode = new ListNode(summ);
                temp->next = newNode;
                temp = newNode;

                summ = 0;
            }
            else{
                summ += head->val;
                head = head->next;
            }
        }
        return dummy->next;
    }
};