class Solution {
public:
    bool hasAlternatingBits(int n) {

        while(n > 0){
            if((n & 1) == ((n>>1) & 1)) return false;

            n /= 2;
        }
        return true;
    }
};