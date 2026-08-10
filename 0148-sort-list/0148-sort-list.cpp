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

    ListNode* mergeSort(ListNode* head, int st, int end){
        if(st >= end) return head;

        int mid = st + (end - st) / 2;
        ListNode* prev = NULL;
        ListNode* temp = head;

        int countOfLeftHalf = mid - st + 1;
        for(int i = 0; i < countOfLeftHalf; i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;

        ListNode* list1 = mergeSort(head, st, mid);
        ListNode* list2 = mergeSort(temp, mid + 1, end);

        return merge(list1, list2);
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }

        return mergeSort(head, 0, n - 1);
    }
};