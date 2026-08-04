class Solution {
public:

    bool isPrefixAndSuffix(string& s1, string& s2){
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2) return false;

        // bool leftCheck = s2.substr(0, n1) == s1;
        // bool rightCheck = s2.substr(n2 - n1, n1) == s1;

        // return leftCheck && rightCheck;
        return s2.starts_with(s1) && s2.ends_with(s1);
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < words.size() - 1; i++){
            for(int j = i + 1; j < words.size(); j++){
                if(isPrefixAndSuffix(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};