class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int row = rStart, col = cStart;
        int times = 1;
        
        vector<vector<int>> ans;

        while(ans.size() < rows * cols){
            for(int i = 0; i < times; i++){
                if(row >= 0 && col >= 0 && row < rows && col < cols){
                    ans.push_back({row, col});
                }
                col++;
            }
            for(int i = 0; i < times; i++){
                if(row >= 0 && col >= 0 && row < rows && col < cols){
                    ans.push_back({row, col});
                }
                row++;
            }

            times++;

            for(int i = 0; i < times; i++){
                if(row >= 0 && col >= 0 && row < rows && col < cols){
                    ans.push_back({row, col});
                }
                col--;
            }
            for(int i = 0; i < times; i++){
                if(row >= 0 && col >= 0 && row < rows && col < cols){
                    ans.push_back({row, col});
                }
                row--;
            }

            times++;
        }

        return ans;
    }
};