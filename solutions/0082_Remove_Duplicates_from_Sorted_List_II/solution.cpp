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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> m;
        while(head != NULL){
            m[head->val]++;
            head = head->next;
        }

        ListNode* dummy = new  ListNode(0);
        ListNode* temp = dummy;
        for(auto& p : m){
            if(p.second == 1){
                ListNode* newNode = new ListNode(p.first);
                temp->next = newNode;
                temp = newNode;
            }
        }
        return dummy->next;
    }
};