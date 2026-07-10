class Solution {
public:

    bool sameFreq(int arr1[26], int arr2[26]){
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }


    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int freq[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            freq[s1[i] - 'a']++;
        }
        int windSize = s1.length();

        for(int i = 0; i < s2.length(); i++){
            int windIdx = 0, idx = i;
            int windFreq[26] = {0};
            while(windIdx < windSize && idx <= s2.length() - 1){
                windFreq[s2[idx] - 'a']++;
                idx++; windIdx++;
            }
            if(sameFreq(freq, windFreq)){
                return true;
            }
        }
        return false;
    }
};