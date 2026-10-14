class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s;

        while(num > 0 && sum >= 9) {
            s += "9";

            sum -= 9;
            num--;
        }

        while(num > 0) {
            if(sum > 0) {
                s += to_string(sum);
                sum = 0;
            }
            else {
                s += "0";
            }

            num--;
        }

        return sum > 0 ? "" : s;
    }
};