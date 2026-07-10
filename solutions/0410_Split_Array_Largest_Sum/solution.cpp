class Solution {
public:
    bool isValid(vector<int>& arr, int n, int m, int max_pages){
        int student = 1, pages = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] > max_pages) return false;
            if(pages + arr[i] <= max_pages) pages += arr[i];
            else {
                student++;
                pages = arr[i];
            }
        }
        return student > m ? false : true;
    }
    int splitArray(vector<int>& nums, int k) {
        int size = nums.size();
        if(k > size) return -1;
        int sum = 0;
        for(int i : nums) sum += i;
        int st = 0, ans = -1;
        int end = sum;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(isValid(nums, size, k, mid)) { ans = mid; end = mid - 1;}
            else st = mid + 1;
        }
        return ans;
    }
};