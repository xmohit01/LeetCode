class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int leftSum = 0;
        for(int i = 0; i < k; i++) leftSum += cardPoints[i];
        if(n == k) return leftSum;

        int ans = leftSum;
        int left_idx = k - 1;
        for(int i = n - 1; i >= n - k; i--){
            leftSum += cardPoints[i];
            leftSum -= cardPoints[left_idx];
            left_idx--;

            ans = max(ans, leftSum);
        }
        return ans;
    }
};