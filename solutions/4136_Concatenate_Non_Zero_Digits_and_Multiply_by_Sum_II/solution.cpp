class Solution {
public:

    long long MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<long long> preSum(n);
        vector<long long> preVal(n);
        vector<long long> power10(n + 1, 1);
        vector<int> nonZero(n, 0);

        for(int i = 1; i <= n; i++){
            power10[i] = (power10[i - 1] * 10) % MOD;
        }
       
        for(int i = 0; i < n; i++){
            int digit = s[i] - '0';

            if(i == 0){
                preSum[i] = digit;
                preVal[i] = digit;
                nonZero[i] = (digit > 0 ? 1 : 0);
            }

            else{
                preSum[i] = preSum[i - 1] + digit;

                if(digit == 0){
                    preVal[i] = preVal[i - 1];
                    nonZero[i] = nonZero[i - 1];
                }
                else{
                    preVal[i] = (preVal[i - 1] * 10 + digit) % MOD;
                    nonZero[i] = nonZero[i - 1] + 1;
                }
            }
        }
        vector<int> ans;
        
        for(auto& querie : queries){
            int left = querie[0], right = querie[1];

            long long sum = preSum[right] - (left > 0 ? preSum[left - 1] : 0);

            long long x = 0;

            int k = nonZero[right] - (left > 0 ? nonZero[left - 1] : 0);

            if(left == 0) x = preVal[right];
            else{
                long long temp = (preVal[left - 1] * power10[k]) % MOD;

                x = (preVal[right] - temp + MOD) % MOD;
            }

            ans.push_back((sum * x) % MOD);
        }
        return ans;
    }
};