class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;

                if(words[j].contains(words[i])){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        return ans;
    }
};