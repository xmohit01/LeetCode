class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(a > 0 || b > 0 || c > 0){
            int cc = c & 1;
            int aa = a & 1;
            int bb = b & 1;

            if(cc == 0) count += aa + bb;
            else{
                if(aa == 0 && bb == 0){
                    count += 1;
                }
            }

            c >>= 1;
            a >>= 1;
            b >>= 1;
        }
        return count;
    }
};