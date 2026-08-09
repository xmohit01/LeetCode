class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int idx1 = 0, idx2 = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> ans;
        while(idx1 < n1 && idx2 < n2){
            if(nums1[idx1] < nums2[idx2]){
                idx1++;
            }
            else if(nums1[idx1] > nums2[idx2]){
                idx2++;
            }
            else{
                ans.push_back(nums1[idx1]);
                idx1++; idx2++;
            }
        }
        return ans;
    }
};