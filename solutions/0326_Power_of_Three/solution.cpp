class Solution {
public:
    bool isPowerOfThree(int n) {
        long long temp = 1162261467;

        if(n > 0 && temp % n == 0) return true;

        return false;
    }
};