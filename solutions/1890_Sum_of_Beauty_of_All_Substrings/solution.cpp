class Solution {
public:
    int beautySum(string s) {
        int total_beauty = 0;
        for(int i = 0; i < s.length(); i++){
            vector<int> freq(26, 0);

            for(int j = i; j < s.length(); j++){
                freq[s[j] - 'a']++;

                int maxi = 0, mini = INT_MAX;

                for(int k = 0; k < 26; k++){
                    int temp = freq[k];
                    
                    if(temp > 0){
                        maxi = max(maxi, temp);
                        mini = min(mini, temp);
                    }
                }
                total_beauty += maxi - mini;
            }
        }
        return total_beauty;
    }
};