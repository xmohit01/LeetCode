class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int temp = nums[i];
            int dig = 0;
            while(temp > 0){
                temp /= 10;
                dig++;
            }
            if(dig % 2 == 0) ans++;
        }
        return ans;
    }
};