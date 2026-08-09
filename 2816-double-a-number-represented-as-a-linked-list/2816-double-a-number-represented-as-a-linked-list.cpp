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
    ListNode* doubleIt(ListNode* head) {
        if(head->val >= 5){
            ListNode* newNode = new ListNode(0);
            newNode->next = head;
            head = newNode;
        }

        ListNode* currNode = head;
        while(currNode != NULL){
            currNode->val = (currNode->val * 2) % 10;

            if(currNode->next != NULL && currNode->next->val >= 5){
                currNode->val += 1;
            }

            currNode = currNode->next;
        }
        return head;
    }
};