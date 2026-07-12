class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> v(n1 + n2);
        int itr = 0;
        int i1 = 0, i2 = 0;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] <= nums2[i2]){
                v[itr++] = nums1[i1++];
            }
            else{
                v[itr++] = nums2[i2++];
            }
        }
        while(i1 < n1){
            v[itr++] = nums1[i1++];
        }
        while(i2 < n2){
            v[itr++] = nums2[i2++];
        }
        if((n1 + n2) % 2 == 0){
            int temp1 = v[(n1+n2)/2];
            int temp2 = v[(n1+n2-1)/2];

            return (temp1 + temp2) / 2.0;
        }
        else{
            return v[(n1+n2)/2];
        }
    }
};