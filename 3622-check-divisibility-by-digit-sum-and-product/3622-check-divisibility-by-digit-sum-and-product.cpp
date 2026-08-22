class Solution {
public:
    int digitSum(int n){
        int digitSum = 0;
        while(n != 0){
            digitSum += n % 10;
            n /= 10;
        }
        return digitSum;
    }
    int digitProduct(int n){
        int digitProduct = 1;
        while(n != 0){
            digitProduct *= n % 10;
            n /= 10;
        }
        return digitProduct;
    }
    bool checkDivisibility(int n) {
        return (n % (digitSum(n) + digitProduct(n))) == 0;
    }
};