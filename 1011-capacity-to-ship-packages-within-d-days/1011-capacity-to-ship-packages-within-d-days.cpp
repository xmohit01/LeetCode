class Solution {
public:

    bool isValid(vector<int>& weights, int days, int mid){
        int n = weights.size();
        int count = 1, temp = 0;
        for(int i = 0; i < n; i++){
            if(temp + weights[i] <= mid){
                temp += weights[i];
            }
            else{
                count++;
                temp = weights[i];
            }
        }
        return count <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        long long max = 0;
        int min = weights[0];
        for(int i = 0; i < n; i++){
            max += weights[i];
            if(weights[i] > min) min = weights[i];
        }

        int ans;
        while(min <= max){
            int mid = min + (max - min) / 2;

            if(isValid(weights, days, mid)){
                ans = mid;
                max = mid - 1;
            }
            else min = mid + 1;
        }
        return ans;
    }
};