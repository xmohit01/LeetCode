class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int st_r = 0, end_r = m - 1;
        int st_c = 0, end_c = n - 1;

        while(st_r <= end_r && st_c <= end_c){
            for(int i = st_c; i <= end_c; i++)
                ans.push_back(matrix[st_r][i]);
            st_r++;
            for(int i = st_r; i <= end_r; i++)
                ans.push_back(matrix[i][end_c]);
            end_c--;
            if(st_r <= end_r){
                for(int i = end_c; i >= st_c; i--)
                    ans.push_back(matrix[end_r][i]);
                end_r--;
            }
            if(st_c <= end_c){
                for(int i = end_r; i >= st_r; i--)
                    ans.push_back(matrix[i][st_c]);
                st_c++;
            }
        }
        return ans;
    }
};