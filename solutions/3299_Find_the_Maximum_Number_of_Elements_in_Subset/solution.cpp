class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int num : nums){
            if(m.count(num)) m[num]++;
            else m[num] = 1;
        }

        int max_len = 0;
        if(m.count(1)) max_len = m[1] % 2 == 0 ? m[1] - 1 : m[1];

        for(auto pair : m){
            long long curr = pair.first;

            if(curr == 1) continue;

            int curr_len = 0;
            while(curr <= 1e9 && m.count(curr) && m[curr] >= 2){
                curr_len += 2;

                curr = curr * curr;
            }

            if(curr <= 1e9 && m.count(curr)) curr_len += 1;
            else curr_len -= 1;

            max_len = max(max_len, curr_len);
        }

        return max_len;
    }
};