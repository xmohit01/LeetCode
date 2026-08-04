class Solution {
public:
    int fact(int n){
        if(n == 0 || n == 1) return 1;
        return n * fact(n - 1);
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(21, 0);
        for(int i : nums){
            freq[i + 10]++;
        }

        int size = fact(n);
        for(int f : freq){
            size /= fact(f);
        }

        vector<vector<int>> ans;
        ans.push_back(nums);
        for(int i = 1; i < size; i++){
            next_permutation(nums.begin(), nums.end());
            ans.push_back(nums);
        }
        return ans;
    }
};