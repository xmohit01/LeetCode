class Solution {
public:
    void merge(vector<int>& nums, int st, int end, int mid){
        vector<int> vec;

        int i = st, j = mid + 1;

        while(i <= mid && j <= end){
            if(nums[i] < nums[j]){
                vec.push_back(nums[i++]);
            }
            else{
                vec.push_back(nums[j++]);
            }
        }
        while(i <= mid){
            vec.push_back(nums[i++]);
        }
        while(j <= end){
            vec.push_back(nums[j++]);
        }

        for(int k = 0; k < vec.size(); k++) nums[st + k] = vec[k];
    }

    void mergeSort(vector<int>& nums, int st, int end){
        if(st >= end) return;

        int mid = st + (end - st) / 2;

        mergeSort(nums, st, mid);
        mergeSort(nums, mid + 1, end);

        merge(nums, st, end, mid);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};