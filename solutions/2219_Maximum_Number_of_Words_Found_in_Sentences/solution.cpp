class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for(int i = 0; i < sentences.size(); i++){
            string sentence = sentences[i];

            int spaces = count(sentence.begin(), sentence.end(), ' ');

            ans = max(ans, spaces);
        }

        return ans + 1;
    }
};