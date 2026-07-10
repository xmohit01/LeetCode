class Solution {
public:
    int hammingWeight(int n) {
        if(n & (n - 1) == 0) return 1;

        int ans = 0;
        while(n != 0){
            if(n % 2) ans++;

            n /= 2;
        }
        return ans;
    }
};