class Solution {
public:
    int partition(vector<int>& nums, int st, int end){
        int mid = st + (end - st) / 2;
        int pivot = nums[mid];

        int i = st;
        int j = end;

        while(i <= j){
            while(nums[i] < pivot) i++;
            while(nums[j] > pivot) j--;

            if(i <= j) {
                swap(nums[i++], nums[j--]);
            }
        }

        return i;
    }

    void quickSort(vector<int>& nums, int st, int end) {
        if(st >= end) return;

        int pivotIdx = partition(nums, st, end);

        quickSort(nums, st, pivotIdx - 1);
        quickSort(nums, pivotIdx, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        
        return nums;
    }
};