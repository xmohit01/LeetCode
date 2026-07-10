class Solution {
public:
    int maxArea(vector<int>& height) {
        int left_index = 0, right_index = height.size() - 1;
        int w = 0, h = 0;
        int currWater = 0, maxWater = 0;
        while(left_index < right_index){
            w = right_index - left_index;
            h = min(height[left_index], height[right_index]);
            currWater = h * w;
            maxWater = max(maxWater, currWater);

            height[left_index] > height[right_index] ? right_index-- : left_index++;

        }
        return maxWater;
    }
};