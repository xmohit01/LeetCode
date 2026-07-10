class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int i = (n - 1) / 2;
        int j = n - 1;

        for(int k = 0; k < n; k++){
            if(k % 2 == 0)
                nums[k] = sorted[i--];
            else
                nums[k] = sorted[j--];
        }
    }
};