class Solution {
public:
    string interpret(string command) {
        int n = command.length();
        string ans = "";
        for(int i = 0; i < n;){
            if(command[i] == 'G'){
                ans += 'G';
                i++;
            }
            else if(command[i] == '(' && command[i + 1] == ')'){
                ans += 'o';
                i += 2;
            }
            else{
                ans += "al";
                i += 4;
            }
        }
        return ans;
    }
};