class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        int a = 0, b = 1;
        for(int i = 0; i < n - 1; i++){
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};