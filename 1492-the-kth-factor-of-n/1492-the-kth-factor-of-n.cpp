class Solution {
public:
    int kthFactor(int n, int k) {
        int num = 0;
        int count = 0;
        while(num <= n && count != k){
            num++;

            if(n % num == 0) count++;
        }
        return count == k ? num : -1;
    }
};