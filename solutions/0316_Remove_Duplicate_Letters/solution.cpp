class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> lastIdx(26, -1);
        for(int i = 0; i < n; i++) lastIdx[s[i] - 'a'] = i;

        vector<int> visited(26, 0);
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(visited[s[i] - 'a'] == 1) continue;

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