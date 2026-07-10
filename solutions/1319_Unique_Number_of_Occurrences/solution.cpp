class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }

        for(auto& pair1 : m){
            for(auto& pair2 : m){
                if(pair1.first != pair2.first && pair1.second == pair2.second) return false;
            }
        }

        return true;
    }
};