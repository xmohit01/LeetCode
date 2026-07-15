class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int temp = arr[0] - 1;
        if(k <= temp) return k;
        else k -= temp;

        int ans;
        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i - 1] == 1){
                continue;
            }
            else{
                int gap = arr[i] - arr[i - 1] - 1;

                if(k <= gap){
                    return arr[i - 1] + k;
                }
                else{
                    k -= gap;
                }
            }
        }
        return arr[n - 1] + k;
    }
};