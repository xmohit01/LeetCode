class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long temp = 0;
        for(int num : nums) temp ^= num;

        long long mask = (unsigned int)temp & (unsigned int)(-temp);

        int a = 0;
        int b = 0;
        
        for(int num : nums){
            if(num & mask) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        
        return {a, b};
    }
};