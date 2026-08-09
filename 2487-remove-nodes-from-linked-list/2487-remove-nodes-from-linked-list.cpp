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
    ListNode* removeNodes(ListNode* head) {
        vector<int> vec;

        vec.push_back(head->val);
        ListNode* temp = head->next;
        while(temp != NULL){
            while(!vec.empty() && vec.back() < temp->val) vec.pop_back();

            vec.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        ListNode* prev = NULL;
        for(int i = 0; i < vec.size(); i++){
            temp->val = vec[i];
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        return head;
    }
};