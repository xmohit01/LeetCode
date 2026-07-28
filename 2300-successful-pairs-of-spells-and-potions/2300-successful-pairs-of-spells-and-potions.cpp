class Solution {
public:
    int helper(long long k, vector<int>& potions, long long success){
        int ans = 0;
        int st = 0, end = potions.size() - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;

            if(potions[mid] * k >= success){
                ans = potions.size() - mid;
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> ans(spells.size());
        for(int i = 0; i < spells.size(); i++){
            ans[i] = helper(spells[i], potions, success);
        }
        return ans;
    }
};