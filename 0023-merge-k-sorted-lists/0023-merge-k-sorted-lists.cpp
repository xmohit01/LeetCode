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
    struct compare{
        bool operator()(const ListNode* l, const ListNode* r){
            return l->val > r->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto& list : lists){
            if(list != NULL){
                pq.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(!pq.empty()){
            ListNode* currNode = pq.top();
            pq.pop();

            tail->next = currNode;
            tail = tail->next;

            if(currNode->next != NULL) pq.push(currNode->next);
        }
        
        return dummy->next;
    }
};