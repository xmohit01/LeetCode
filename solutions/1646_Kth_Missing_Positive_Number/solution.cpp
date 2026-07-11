class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        // int temp = arr[0] - 1;
        // if(k <= temp) return k;
        // else k -= temp;

        // int ans;
        // for(int i = 1; i < n; i++){
        //     if(arr[i] - arr[i - 1] == 1){
        //         continue;
        //     }
        //     else{
        //         int gap = arr[i] - arr[i - 1] - 1;

        //         if(k <= gap){
        //             return arr[i - 1] + k;
        //         }
        //         else{
        //             k -= gap;
        //         }
        //     }
        // }
        // return arr[n - 1] + k;


        int st = 0, end = n - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            
            int missing = arr[mid] - mid - 1;
            
            if(missing < k){
                st = mid + 1;
            }
            else end = mid - 1;
        }

        return st + k;
    }
};