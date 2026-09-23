class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long total = 0;

        for(int num : nums){
            total += num;
        }

        // Instead of removing elements summing to x, find the longest subarray with sum = total - x.
        long long target = total - x;

        // Not Possible
        if(target < 0) return -1;
        // If x == total sum of the array we will have to remove whole array
        if(target == 0) return nums.size();

        int left = 0;
        long long sum = 0;
        int maxLen = -1;

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];

            // Shrink the window until its sum becomes <= target.
            while(sum > target){
                sum -= nums[left];
                left++;
            }

            // Keep the longest subarray with sum exactly equal to target.
            if(sum == target){
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // Remove everything outside the longest valid subarray.
        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};