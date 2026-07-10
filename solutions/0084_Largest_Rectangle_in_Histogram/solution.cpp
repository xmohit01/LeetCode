class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        vector<int> rightSmallest(n);
        vector<int> leftSmallest(n);
        stack<int> s;
        for(int i = n - 1; i >= 0; i--){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();

            if(s.empty()) rightSmallest[i] = n;
            else rightSmallest[i] = s.top();

            s.push(i);
        }
        s = stack<int>();
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]) s.pop();

            if(s.empty()) leftSmallest[i] = -1;
            else leftSmallest[i] = s.top();

            s.push(i);
        }

        for(int i = 0; i < n; i++){
            int height = heights[i];
            // while(left >= 0 && heights[i] <= heights[left]) left--;
            // while(right < n && heights[i] <= heights[right]) right++;

            int width = rightSmallest[i] - leftSmallest[i] - 1;
            ans = max(ans, height * width);
        }
        return ans;
    }
};