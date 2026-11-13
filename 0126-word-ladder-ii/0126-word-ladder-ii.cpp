class Solution {
public:
    unordered_map<string, int> m;
    vector<vector<string>> ans;
    int n;

    void dfs(string word, vector<string>& seq, string& beginWord) {
        if(word == beginWord) {
            reverse(seq.begin(), seq.end());

            ans.push_back(seq);

            reverse(seq.begin(), seq.end());
            
            return;
        }

        int steps = m[word];

        for(int i = 0; i < n; i++) {
            char original = word[i];

            for(int j = 0; j < 26; j++) {
                char ch = 'a' + j;

                word[i] = ch;

                if(m.find(word) != m.end() && m[word] < steps) {
                    seq.push_back(word);

                    dfs(word, seq, beginWord);

                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        // * * * * *  !!! Enough for interviews watchers !!! * * * * *

        // int n = beginWord.length();

        // unordered_set<string> s;
        // for(auto& word : wordList) s.insert(word);

        // if(s.find(endWord) == s.end()) return {};

        // queue<vector<string>> q;
        // q.push({beginWord});
        // s.erase(beginWord);

        // int shortestLen = INT_MAX;

        // vector<vector<string>> ans;

        // while(!q.empty()) {
        //     int sz = q.size();

        //     vector<string> toRemove;

        //     for(int i = 0; i < sz; i++) {
        //         vector<string> curr = q.front();
        //         q.pop();

        //         if(curr.size() > shortestLen) {
        //             break;
        //         }

        //         string endStr = curr.back();

        //         if(endStr == endWord) {
        //             shortestLen = curr.size();

        //             ans.push_back(curr);

        //             continue;
        //         }

        //         for(int j = 0; j < n; j++) {
        //             char org = endStr[j];

        //             for(int k = 0; k < 26; k++) {
        //                 char ch = k + 'a';

        //                 if(ch == org) continue;

        //                 endStr[j] = ch;

        //                 if(s.find(endStr) != s.end()) {
        //                     toRemove.push_back(endStr);

        //                     curr.push_back(endStr);

        //                     q.push(curr);

        //                     curr.pop_back();
        //                 }
        //             }

        //             endStr[j] = org;
        //         }
        //     }

        //     for(auto& str : toRemove) s.erase(str);
        // }

        // return ans;

        

        // - - - !!! DO NOT ENTER !!! - - -

        n = beginWord.length();

        unordered_set<string> s;
        for(auto& word : wordList) s.insert(word);

        queue<string> q;
        q.push(beginWord);
        s.erase(beginWord);
        m[beginWord] = 1;

        while(!q.empty()) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                string word = q.front();
                q.pop();

                int steps = m[word];

                for(int j = 0; j < n; j++) {
                    char original = word[j];

                    for(int k = 0; k < 26; k++) {
                        char ch = k + 'a';

                        if(ch == original) continue;

                        word[j] = ch;

                        if(s.find(word) != s.end()) {
                            s.erase(word);

                            m[word] = steps + 1;

                            q.push(word);
                        }
                    }

                    word[j] = original;
                }
            }
        }

        if(m.find(endWord) != m.end()) {
            vector<string> seq;
            seq.push_back(endWord);

            dfs(endWord, seq, beginWord);
        }

        return ans;
    }
};