class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProfit = 0, buyPrice = prices[0];
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] > buyPrice){
                maxProfit = max(maxProfit, prices[i] - buyPrice);
            }
            buyPrice = min(buyPrice, prices[i]);
        }

        return maxProfit;

    }
};
