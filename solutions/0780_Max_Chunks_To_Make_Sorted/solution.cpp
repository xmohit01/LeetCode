class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        int max_far = 0, ans = 0;
        for(int i = 0; i < n; i++){
            max_far = max(max_far, arr[i]);

            if(max_far == i) ans++;
        }

        return ans;
    }
};