class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        long long total_gas = 0, total_cost = 0;
        for(int i = 0; i < n; i++){
            total_gas += gas[i];
            total_cost += cost[i];
        }

        if(total_cost > total_gas) return -1;

        int ans = 0;
        int currGas = 0;
        for(int i = 0; i < n; i++){
            currGas += gas[i] - cost[i];

            if(currGas < 0){
                currGas = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
};