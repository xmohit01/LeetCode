class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        
        vector<int> last_seen(3, -1);

        for(int i = 0; i < n; i++){
            last_seen[s[i] - 'a'] = i;

            if(last_seen[0] != -1 && last_seen[0] != -1 && last_seen[2] != -1){
                ans += min({last_seen[0], last_seen[1], last_seen[2]}) + 1;
            }
        }

        return ans;
    }
};