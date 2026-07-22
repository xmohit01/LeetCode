class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for(int i = 0; i < m; i++){
            int temp = 0;
            int st = 0, end = n - 1;
            while(st <= end){
                int mid = st + (end - st) / 2;

                if(grid[i][mid] < 0){
                    temp = n - mid;
                    end = mid - 1;
                }
                else st = mid + 1;
            }
            count += temp;
        }
        return count;
    }
};