class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        sort(stones.begin(), stones.end());

        while(stones.size() > 1){
            int n = stones.size();

            int temp1 = stones[n - 1];
            int temp2 = stones[n - 2];
            stones.pop_back();
            stones.pop_back();

            if(temp1 - temp2 != 0) stones.push_back(abs(temp1 - temp2));

            sort(stones.begin(), stones.end());
        }

        return stones.empty() ? 0 : stones[0];
    }
};