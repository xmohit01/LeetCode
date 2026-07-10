class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0;
        int n = columnTitle.length();
        
        for(int i = 0; i < n; i++){
            ans = ans * 26 + (columnTitle[i] - 'A' + 1);

            
        }

        return ans;
    }
};