class Solution {
public:
    bool judgeSquareSum(int c) {
        long long st = 0;
        long long end = sqrt(c);

        while(st <= end){
            long long sum = (st * st) + (end * end);

            if(sum == c) return true;

            else if(sum > c) end--;
            else st++;
        }
        return false;
    }
};