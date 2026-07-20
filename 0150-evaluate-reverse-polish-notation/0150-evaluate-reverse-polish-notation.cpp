class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto& token : tokens){
            string temp = token;

            if(temp != "+" && temp != "-" && temp != "/" && temp != "*"){
                st.push(stoi(temp));
                continue;
            }

            int second = st.top(); st.pop();
            int first = st.top(); st.pop();

            int opr;
            if(temp == "+") opr = first + second;
            else if(temp == "-") opr = first - second;
            else if(temp == "/") opr = first / second;
            else opr = first * second;

            st.push(opr);
        }
        return st.top();
    }
};

