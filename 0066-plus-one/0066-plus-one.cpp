class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int i;
        for(i = n - 1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i]++;
                break;
            }
        }
        if(i != -1){
            for(int j = i + 1; j < n; j++) digits[j] = 0;
            return digits;
        }
        else{
            vector<int> ans(n + 1, 0);
            ans[0] = 1;
            return ans;
        }
    }
};