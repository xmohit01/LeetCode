class Solution {
public:
    bool isHappy(int n) {
        while(n != 1){
            if(n == 7) return true;
            if(n < 10) return false;

            int temp = n;
            int count = 0;
            while(temp != 0){
                count += pow(temp % 10, 2);
                temp /= 10;
            }
            n = count;
        }

        return true;
    }
};