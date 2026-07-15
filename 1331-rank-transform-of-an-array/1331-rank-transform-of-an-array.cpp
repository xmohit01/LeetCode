class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return {};
        vector<int> v(arr.begin(), arr.end());
        sort(v.begin(), v.end());
        unordered_map<int, int> m;

        m[v[0]] = 1;
        int temp = 1;
        for(int i = 1; i < n; i++){
            while(i < n && v[i] == v[i - 1]) i++;

            temp++;
            if(i < n) m[v[i]] = temp;
        }

        for(int i = 0; i < n; i++) arr[i] = m[arr[i]];

        return arr;
    }
};