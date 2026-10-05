class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        // METHOD - 1
        // priority_queue<pair<int, int>> maxHeap;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // int l = 0, r = 0;
        // int maxLen = 0;

        // for(int r = 0; r < n; r++) {
        //     maxHeap.push({nums[r], r});
        //     minHeap.push({nums[r], r});

        //     while(maxHeap.top().first - minHeap.top().first > limit) {
        //         l = min(maxHeap.top().second, minHeap.top().second) + 1;

        //         while(maxHeap.top().second < l) {
        //             maxHeap.pop();
        //         }
        //         while(minHeap.top().second < l) {
        //             minHeap.pop();
        //         }
        //     }

        //     maxLen = max(maxLen, r - l + 1);
        // }

        // return maxLen;


        multiset<int> ms;

        int l = 0, r = 0;
        int maxLen = 0;

        for(int r = 0; r < n; r++) {

            ms.insert(nums[r]);

            while(*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[l++]));
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};