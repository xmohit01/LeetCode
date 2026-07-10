class Solution {
public:
    bool isPowerOfFour(int n) {
        bool twos = false;

        if(n > 0 && (((n) & (n - 1)) == 0)) twos = true;

        if(twos && (n - 1) % 3 == 0) return true;
        return false;
    }
};