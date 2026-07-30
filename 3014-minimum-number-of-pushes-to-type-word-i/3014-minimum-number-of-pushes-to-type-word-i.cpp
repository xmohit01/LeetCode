class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> freq(26, 0);
        for(char c : word){
            freq[c - 'a']++;
        }

        int distinct = 0;
        
        sort(freq.rbegin(), freq.rend());

        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                distinct++;
                if(distinct <= 8){
                    ans += freq[i];
                }
                else if(distinct <= 16){
                    ans += freq[i] * 2;
                }
                else if(distinct <= 24){
                    ans += freq[i] * 3;
                }
                else{
                    ans += freq[i] * 4;
                }
            }
        }
        return ans;
    }
};