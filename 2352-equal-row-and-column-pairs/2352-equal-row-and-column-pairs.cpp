class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rows;

        for(int i = 0; i < n; i++){
            rows[grid[i]]++;
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            vector<int> temp(n);
            for(int j = 0; j < n; j++){
                temp[j] = grid[j][i];
            }
            
            count += rows[temp];
        }

        return count;
    }
};