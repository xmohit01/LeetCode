class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> ans;

        prev.insert(arr[0]);

        for(int x : arr){
            vector<int> old(prev.begin(), prev.end());    // last index tak ke subarray ORs

            prev.clear();
            prev.insert(x);

            for(int num : old){
                prev.insert(num | x);
            }
            for(int num : prev){
                ans.insert(num);
            }
        }

        return ans.size();
    }
};