class Solution {
public:
    double myPow(double x, int n) {

        if(n == 0) return 1.0;
        if(x == 0) return 0;
        if(x == 1) return 1.0;

        if(x == -1){
            return n % 2 == 0 ? 1 : -1;
        }

        long binaryForm = n;
        double answer = 1;
        if(n < 0){
            x = 1 / x;
            binaryForm = -binaryForm;
        }
            while(binaryForm >  0){
                if(binaryForm % 2 == 1){
                    answer *= x;
                }
                x *= x;
                binaryForm /= 2;
            }
            return answer;
    }
};