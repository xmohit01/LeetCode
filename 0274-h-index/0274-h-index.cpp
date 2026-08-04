class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());

        int temp = 1;
        int ans = 0;

        for(int i = n - 1; i >= 0; i--){
            if(citations[i] >= temp){
                ans = temp;
                temp++;
            }
            else break;
        }
        return ans;
    }
};