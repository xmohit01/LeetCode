class Solution {
public:
    bool isPossible(vector<int>& price, int k, int mid){
        int count = 1, lastVis = price[0];
        for(int i = 1; i < price.size(); i++){
            if(price[i] - lastVis >= mid){
                count++;
                lastVis = price[i];
            }
        }
        return count >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();

        int st = 0, end = price[n - 1] - price[0];
        int ans = 0;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(isPossible(price, k, mid)){
                ans = mid;
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
};