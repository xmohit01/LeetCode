class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num) return "";

        string s;

        while(num--) {
            int dig = min(9, sum);
            s.push_back(dig + '0');
            sum -= dig;
        }

        return s;
    }
};