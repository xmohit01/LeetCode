class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> prime(n + 1, true);
        int count = 1;
        
        for(int num = 3; num < n; num += 2){
            if(prime[num]){
                count++;

                if(num <= n / num){
                    for(int i = num * num; i < n; i += 2 * num){
                        prime[i] = false;
                    }
                }
            }
        }
        return count;
    }
};