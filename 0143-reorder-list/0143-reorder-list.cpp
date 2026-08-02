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
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;
        while(fast != NULL && fast->next != NULL){
            count++;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = head;

        vector<ListNode*> firstHalf;
        vector<ListNode*> secondHalf;

        while(slow != NULL){
            count++;
            firstHalf.push_back(fast);
            secondHalf.push_back(slow);

            fast = fast->next;
            slow = slow->next;
        }
        if(count % 2 == 1){
            firstHalf.pop_back();
        }

        int size1 = firstHalf.size();
        int size2 = secondHalf.size();
        reverse(secondHalf.begin(), secondHalf.end());

        int i = 0, j = 0;
        while(i < size1 && j < size2){
            
            firstHalf[i]->next = secondHalf[j];
            i++;

            if(i < size1){
                secondHalf[j]->next = firstHalf[i];
            }
            j++;
        }

        if(size1 < size2 && size1 > 0){
            secondHalf[size2 - 2]->next = secondHalf[size2 - 1];
        }

        secondHalf[secondHalf.size() - 1]->next = NULL;
    }
};