class Solution {
public:

    bool isValid(vector<int>& bloomDay, int m, int k, int h){
        int count = 0;
        int temp = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= h){
                temp++;
            }
            else{
                temp = 0;
            }
            if(temp == k){
                count++;
                temp = 0;
            }
        }
        return count >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // m bouquets, k flowers

        int n = bloomDay.size();
        if(n < (long long)m * k) return -1;

        auto min_it = min_element(bloomDay.begin(), bloomDay.end());
        auto max_it = max_element(bloomDay.begin(), bloomDay.end());

        int st = *min_it, end = *max_it;

        int ans = -1;
        while(st <= end){
            int mid = st + (end - st) / 2;

            if(isValid(bloomDay, m, k, mid)){
                ans = mid;
                end = mid - 1;
            }
            else st = mid + 1;
        }
        return ans;
    }
};