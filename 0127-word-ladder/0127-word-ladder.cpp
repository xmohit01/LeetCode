class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int k = wordList.size();
        int n = beginWord.length();

        unordered_set<string> s;
        for(auto& word : wordList) s.insert(word);

        int cnt = 1;

        queue<string> q;
        q.push(beginWord);

        while(!q.empty()) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                string word = q.front();
                q.pop();

                if(word == endWord) return cnt;

                for(int j = 0; j < n; j++) {
                    for(int k = 0; k < 26; k++) {
                        char ch = k + 'a';

                        if(ch == word[j]) continue;

                        string temp = word;
                        temp[j] = ch;

                        if(s.find(temp) != s.end()) {
                            s.erase(temp);

                            q.push(temp);
                        }
                    }
                }
            }

            cnt++;
        }

        return 0;
    }
};