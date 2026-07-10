class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        
        for(int i = 2 * n - 1; i >= 0; i--){
            int currIdx = i % n;

            while(!st.empty() && st.top() <= nums[currIdx]) st.pop();

            if(st.empty()) ans[currIdx] = -1;
            else ans[currIdx] = st.top();

            st.push(nums[currIdx]);
        }

        return ans;
    }
};