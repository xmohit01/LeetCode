class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        int score = 0;
        for(int i = 0; i < n; i++){
            sort(nums[i].begin(), nums[i].end());
        }
        for(int i = 0; i < m; i++){
            int temp = nums[0][i];
            for(int j = 1; j < n; j++){
                if(nums[j][i] > temp) temp = nums[j][i];
            }
            score += temp;
        }
        return score;
    }
};