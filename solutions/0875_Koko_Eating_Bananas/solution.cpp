class Solution {
public:

    long long helper(vector<int>& piles, int k){
        long long temp = 0;
        for(int i : piles){
            temp += (i + k - 1) / k;
        }
        return temp;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        auto it = max_element(piles.begin(), piles.end());
        int min = 1;
        int max = *it;

        int ans;
        while(min <= max){
            int mid = min + (max - min) / 2;

            if(helper(piles, mid) <= h){
                ans = mid;
                max = mid - 1;
            }
            else min = mid + 1;
        }
        return ans;
    }
};