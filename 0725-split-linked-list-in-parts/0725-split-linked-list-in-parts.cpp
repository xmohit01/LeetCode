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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        int size = count / k;
        int extraSize = count % k;

        vector<ListNode*> ans;
        temp = head;
        for(int i = 0; i < k; i++){
            int currSize = size;
            if(extraSize > 0){
                extraSize--;
                currSize++;
            }
            if(temp != NULL){
                ans.push_back(temp);
                for(int j = 0; j < currSize - 1; j++){
                    temp = temp->next;
                }
                ListNode* next = temp->next;
                temp->next = NULL;
                temp = next;
            }
            else{
                ans.push_back({});
            }
        }
        return ans;
    }
};