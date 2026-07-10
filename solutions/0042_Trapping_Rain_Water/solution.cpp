class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // vector<int> rightMax(n);
        // vector<int> leftMax(n);
        
        // leftMax[0] = height[0];
        // for(int i = 1; i < n; i++){
        //     leftMax[i] = max(leftMax[i - 1], height[i]);
        // }

        // rightMax[n - 1] = height[n - 1];
        // for(int i = n - 2; i >= 0; i--){
        //     rightMax[i] = max(rightMax[i + 1], height[i]);
        // }

        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     int temp = min(leftMax[i], rightMax[i]);
        //     ans += temp - height[i];
        // }
        // return ans;

        int ans = 0;
        int left = 0, right = n - 1;
        int lMax = 0, rMax = 0;
        while(left < right){
            lMax = max(lMax, height[left]);
            rMax = max(rMax, height[right]);

            if(lMax < rMax) ans += lMax - height[left++];
            else ans += rMax - height[right--];

        }
        return ans;
    }
};