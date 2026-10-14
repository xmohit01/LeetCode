class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s;

        while(num > 0) {
            if(sum > 9) {
                s.push_back('9');
                sum -= 9;
            }
            else if(sum > 0) {
                s.push_back(sum + '0');
                sum = 0;
            }
            else {
                s.push_back('0');
            }

            num--;
        }

        return sum > 0 ? "" : s;
    }
};