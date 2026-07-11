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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        queue<ListNode*> q;
        ListNode* temp = head->next;

        while(temp != NULL){
            q.push(temp);

            if(temp->next != NULL) temp = temp->next->next;
            else break;
        }

        temp = head;
        ListNode* copy = head;
        while(temp != NULL && temp->next != NULL){
            temp = temp->next->next;
            if(temp != NULL){
                copy->next = temp;
                copy = copy->next;
            }
        }

        while(!q.empty()){
            copy->next = q.front();
            copy = copy->next;
            q.pop();
        }
        copy->next = NULL;
        
        return head;
    }
};