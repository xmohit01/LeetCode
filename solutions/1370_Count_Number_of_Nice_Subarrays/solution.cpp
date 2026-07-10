class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++) nums[i] %= 2;

        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         if(count(nums.begin() + i, nums.begin() + j + 1, 1) == k) ans++;
        //     }
        // }

        // return ans;

        int odd_count = 0, ans = 0;
        queue<int> ones;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                ones.push(i);
                if(ones.size() == k){
                    int left_idx = ones.front() - 1;
                    ones.pop();
                    int lft = 1;
                    while(left_idx >= 0 && nums[left_idx] == 0){
                        lft++;
                        left_idx--;
                    }
                    int rght = 1, right_idx = i + 1;
                    while(right_idx < n && nums[right_idx] == 0){
                        rght++;
                        right_idx++;
                    }

                    ans += lft * rght;
                }
            }
        }
        return ans;
    }
};