class Solution {
public:
    int findGCD(vector<int>& nums) {
       int n = nums.size();

       int a = nums[0], b = nums[0];
       for(int i = 0; i < n; i++){
       if(a > nums[i]) a = nums[i];
       if(b < nums[i]) b = nums[i];
       }

    while(a > 0 && b > 0){
        if(a > b) a %= b;
        else b %= a;
    }
    return (a == 0) ? b : a;
       
    }
};