class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = nums[0];
        for(int& num : nums){
            maxi = max(maxi, num);
            num = gcd(num, maxi);
        }

        sort(nums.begin(), nums.end());

        long long ans = 0;
        int st = 0, end = nums.size() - 1;
        while(st < end){
            ans += gcd(nums[st], nums[end]);
            st++; end--;
        }

        return ans;
    }
};
