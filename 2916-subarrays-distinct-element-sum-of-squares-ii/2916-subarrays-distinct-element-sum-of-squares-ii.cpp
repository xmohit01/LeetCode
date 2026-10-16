class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;
    int n;

    vector<ll> sumSegTree;
    vector<ll> sqSumSegTree;
    vector<ll> lazyTree;

    // Add val to every element and update sum and sum of squares.
    void lazzyAddition(int idx, int l, int r, int val) {
        ll len = r - l + 1;

        sqSumSegTree[idx] += 2 * val * sumSegTree[idx] + len * val * val;
        sumSegTree[idx] += len * val;
    }

    void updateRange(int st, int end, int idx, int l, int r, int val) {
        // Apply pending lazy update before processing this segment.
        if(lazyTree[idx] != 0) {
            lazzyAddition(idx, l, r, lazyTree[idx]);

            if(l != r) {
                lazyTree[2 * idx + 1] += lazyTree[idx];
                lazyTree[2 * idx + 2] += lazyTree[idx];
            }

            lazyTree[idx] = 0;
        }

        // out of range
        if(l > end || r < st || l > r) return;

        // completely within range
        if(l >= st && r <= end) {
            lazzyAddition(idx, l, r, val);

            if(l != r) {
                lazyTree[2 * idx + 1] += val;
                lazyTree[2 * idx + 2] += val;
            }

            return;
        }

        // Partial overlap
        int mid = l + (r - l) / 2;

        updateRange(st, end, 2 * idx + 1, l, mid, val);
        updateRange(st, end, 2 * idx + 2, mid + 1, r, val);

        // Merge results from both children.
        sumSegTree[idx] = sumSegTree[2 * idx + 1] + sumSegTree[2 * idx + 2];
        sqSumSegTree[idx] = sqSumSegTree[2 * idx + 1] + sqSumSegTree[2 * idx + 2];
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();

        sumSegTree.assign(4 * n, 0);
        sqSumSegTree.assign(4 * n, 0);
        lazyTree.assign(4 * n, 0);

        vector<int> lastSeenIdx(100001, -1);
        ll result = 0;

        for(int i = 0; i < n; i++) {
            // Only these starting indices gain a new distinct element.
            int st = lastSeenIdx[nums[i]] + 1;
            int end = i;

            updateRange(st, end, 0, 0, n - 1, 1);

            result = (result + sqSumSegTree[0]) % MOD;

            lastSeenIdx[nums[i]] = i;
        }

        return result;
    }
};