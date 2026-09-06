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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int st_r = 0, end_r = m - 1;
        int st_c = 0, end_c = n - 1;

        while(st_r <= end_r && st_c <= end_c && head != NULL){
            for(int i = st_c; i <= end_c && head != NULL; i++){
                matrix[st_r][i] = head->val;
                head = head->next;
            }
            st_r++;
            for(int i = st_r; i <= end_r && head != NULL; i++){
                matrix[i][end_c] = head->val;
                head = head->next;
            }
            end_c--;
            if(st_r <= end_r){
                for(int i = end_c; i >= st_c && head != NULL; i--){
                    matrix[end_r][i] = head->val;
                    head = head->next;
                }
                end_r--;
            }
            if(st_c <= end_c){
                for(int i = end_r; i >= st_r && head != NULL; i--){
                    matrix[i][st_c] = head->val;
                    head = head->next;
                }
                st_c++;
            }
        }

        return matrix;
    }
};