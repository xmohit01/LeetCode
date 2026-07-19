class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        
        long long inc = n / 2;
        long long dec = inc - 1;

        return (s + (inc * m) - dec);
    }
};