class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count = 0;
        while(c != 0){
            int cc = c & 1;
            int aa = a & 1;
            int bb = b & 1;

            if(cc == 0) count += aa + bb;
            else{
                if(aa || bb) count += 0;
                else count += 1;
            }

            c >>= 1;
            a >>= 1;
            b >>= 1;
        }
        while(a != 0){
            if(a & 1){
                count++;
            }
            a >>= 1;
        }
        while(b != 0){
            if(b & 1){
                count++;
            }
            b >>= 1;
        }
        return count;
    }
};