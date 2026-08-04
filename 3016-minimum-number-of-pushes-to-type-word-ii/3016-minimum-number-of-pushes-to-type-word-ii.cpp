class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char c : word){
            freq[c - 'a']++;
        }
        
        sort(freq.rbegin(), freq.rend());

        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] == 0) break;

            if(i + 1 <= 8){
                ans += freq[i];
            }
            else if(i + 1 <= 16){
                ans += freq[i] * 2;
            }
            else if(i + 1 <= 24){
                ans += freq[i] * 3;
            }
            else{
                ans += freq[i] * 4;
            }
        }
        return ans;
    }
};