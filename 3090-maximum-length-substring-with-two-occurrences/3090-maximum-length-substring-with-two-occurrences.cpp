class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> freq(27, 0);

        int ans = 0, count = 0, left = 0;
        for(int right = 0; right < n; right++){
            int currChar = s[right] - 'a';

            freq[currChar]++;
            
            while(freq[currChar] > 2){
                freq[s[left++] - 'a']--;
            }

            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};