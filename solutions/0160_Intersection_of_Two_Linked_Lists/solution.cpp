/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode* startB = headB;
        // while(headA != NULL){
        //     headB = startB;
        //     while(headB != NULL){
        //         if(headA == headB) return headA;
        //         headB = headB->next;
        //     }
        //     headA = headA->next;
        // }
        // return NULL;

        unordered_map<ListNode*, int> m;
        while(headA != NULL){
            m[headA] = headA->val;
            headA = headA->next;
        }
        while(headB != NULL){
            if(m.contains(headB)) return headB;

            headB = headB->next;
        }
        return NULL;
    }
};