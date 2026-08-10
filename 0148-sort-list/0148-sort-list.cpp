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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(head1 != NULL && head2 != NULL){
            if(head1->val <= head2->val){
                temp->next = head1;
                head1 = head1->next;
                temp = temp->next;
            }
            else{
                temp->next = head2;
                head2 = head2->next;
                temp = temp->next;
            }
        }
        if(head1 != NULL){
            temp->next = head1;
        }
        if(head2 != NULL){
            temp->next = head2;
        }

        ListNode* sortedHead = dummy->next;
        delete dummy;
        return sortedHead;
    }

    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* mid = getMid(head);
        ListNode* rightHead = mid->next;
        mid->next = NULL;

        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(rightHead);

        return merge(leftSorted, rightSorted);
    }
};