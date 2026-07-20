class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto& token : tokens){

            if(token != "+" && token != "-" && token != "/" && token != "*"){
                st.push(stoi(token));
                continue;
            }

            int second = st.top(); st.pop();
            int first = st.top(); st.pop();

            int opr;
            if(token == "+") opr = first + second;
            else if(token == "-") opr = first - second;
            else if(token == "/") opr = first / second;
            else opr = first * second;

            st.push(opr);
        }
        return st.top();
    }
};

