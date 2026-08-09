class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        int st_r = 0, end_r = n - 1;
        int st_c = 0, end_c = n - 1;

        int temp = 1;
        while(st_r <= end_r && st_c <= end_c){
            for(int i = st_c; i <= end_c; i++)
                ans[st_r][i] = temp++;
            st_r++;
            for(int i = st_r; i <= end_r; i++)
                ans[i][end_c] = temp++;
            end_c--;
            if(st_r <= end_r){
                for(int i = end_c; i >= st_c; i--)
                    ans[end_r][i] = temp++;
                end_r--;
            }
            if(st_c <= end_c){
                for(int i = end_r; i >= st_r; i--)
                    ans[i][st_c] = temp++;
                st_c++;
            }
        }
        return ans;
    }
};