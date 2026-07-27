class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num1 = 1, num2 = 1;

        for(int val : nums){
            if(val > num1){
                num2 = num1;
                num1 = val;
            }
            else if(val > num2){
                num2 = val;
            }
        }
        return (num1 - 1) * (num2 - 1);
    }
};