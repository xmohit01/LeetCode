class Solution {
public:

    bool isValid(vector<int>& nums, int threshold, int t){
        int n = nums.size();

        int sum = 0;
        for(int i : nums) sum += (i + t - 1) / t;

        return sum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        auto max_it = max_element(nums.begin(), nums.end());
        int min = 1, max = *max_it;

        int ans;
        while(min <= max){
            int mid = min + (max - min) / 2;

            if(isValid(nums, threshold, mid)){
                ans = mid;
                max = mid - 1;
            }
            else min = mid + 1;
        }
        return ans;
    }
};