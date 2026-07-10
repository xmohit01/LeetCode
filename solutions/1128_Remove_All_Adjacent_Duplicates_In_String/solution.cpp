class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();

        stack<char> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() == s[i]){
                st.pop();
                i++;
            }
            if(i < n) st.push(s[i]);
        }

        if(st.empty()) return "";

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};