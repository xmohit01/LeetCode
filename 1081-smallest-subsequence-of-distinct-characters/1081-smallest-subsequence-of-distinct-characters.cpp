class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        stack<char> st;
        vector<int> visited(26, 0);
        vector<int> lastIdx(26, 0);

        for(int i = 0; i < n; i++){
            lastIdx[s[i] - 'a'] = i;
        }

        for(int i = 0; i < n; i++){
            if(visited[s[i] - 'a'] == 1){
                continue;
            }
            while(!st.empty() && st.top() > s[i] && lastIdx[st.top() - 'a'] > i){
                visited[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(s[i]);
            visited[s[i] - 'a'] = 1;
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};