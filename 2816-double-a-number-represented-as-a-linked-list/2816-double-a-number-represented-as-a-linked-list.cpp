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
        vector<int> vec;

        ListNode* temp = head;
        while(temp != NULL){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        int carry = 0;
        for(int i = vec.size() - 1; i >= 0; i--){
            vec[i] *= 2;
            vec[i] += carry;
            carry = vec[i] / 10;
            vec[i] = vec[i] % 10;
        }
        temp = head;
        int i = 0;
        while(temp != NULL){
            temp->val = vec[i++];
            temp = temp->next;
        }
        if(carry == 0) return head;

        ListNode* newHead = new ListNode(carry);
        newHead->next = head;
        return newHead;
    }
};