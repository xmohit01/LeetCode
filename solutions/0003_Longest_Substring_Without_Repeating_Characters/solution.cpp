class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(256, -1);
        int n = s.length();
        int maxlen = 0, temp = 0;

        for(int i = 0; i < n; i++){
            if(last_seen[s[i]] != -1 && last_seen[s[i]] >= temp){
                temp = last_seen[s[i]] + 1;
            }
            int curr = i - temp + 1;
            maxlen = max(maxlen, curr);

            last_seen[s[i]] = i;
        }

        return maxlen;
    }
};