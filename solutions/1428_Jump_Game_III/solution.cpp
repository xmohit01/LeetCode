class Solution {
public:

    bool helper(vector<int>& arr, int start){
        bool left = false, right = false;

        int temp = arr[start];
        if (temp < 0) return false;
        arr[start] = -1;

        if(temp == 0) return true;
        if(start - temp >= 0){
            left =  helper(arr, start - temp);
        }
        if(start + temp < arr.size()){
            right =  helper(arr, start + temp);
        }
        return left || right;
    }

    bool canReach(vector<int>& arr, int start) {
        return helper(arr, start);
    }
};