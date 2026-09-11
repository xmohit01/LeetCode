class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long ans = 0;
        long long divi = abs((long long)dividend);
        long long div = abs((long long)divisor);
        
        while(divi >= div){
            long long temp = div;
            long long multiple = 1;

            while((temp << 1) <= divi){
                temp <<= 1;
                multiple <<= 1;
            }

            divi -= temp;
            ans += multiple;
        }

        if((dividend >= 0) != (divisor >= 0)) return -ans;

        return ans;
    }
};