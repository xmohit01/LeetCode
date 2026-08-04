class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string s = "123456789";

        for(int i = 0; i < 9; i++){
            for(int size = 1; size <= 9 - i; size++){
                string temp = s.substr(i, size);

                int k = stoi(temp);
                if(k >= low && k <= high) ans.push_back(k);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};