class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int size = patterns.size();

        int ans = 0;
        for(int i = 0; i < size; i++){
            if(word.contains(patterns[i])) ans++;
        }

        return ans;
    }
};