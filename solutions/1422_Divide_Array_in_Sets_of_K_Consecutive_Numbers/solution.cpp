class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;

        map<int, int> freq;
        for(int i = 0; i < n; i++) freq[nums[i]]++;

        for(auto& p : freq){
            int currFreq = p.second;
            while(currFreq--){
                for(int i = p.first + 1; i < p.first + k; i++){
                    if(freq[i] == 0) return false;

                    freq[i]--;
                }
            }
        }
        return true;
    }
};