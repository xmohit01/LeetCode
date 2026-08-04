class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int size = target.size();
        vector<string> ans;

        int idx = 0;
        for(int i = 1; i <= n; i++){
            if(target[idx] == i){
                ans.push_back("Push");
                idx++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(idx == size) break;
        }
        return ans;
    }
};