class Solution {
public:
    string decodeString(string s) {
        stack<string> strings;
        stack<int> counts;
        string curr = "";
        int count = 0;

        for(int i = 0; i < s.length(); i++){
            if(isdigit(s[i])){
                count = count * 10 + (s[i] - '0');
            }

            else if(s[i] == '['){
                counts.push(count);
                strings.push(curr);

                count = 0;
                curr = "";
            }

            else if(s[i] == ']'){
                string tempString = strings.top();
                strings.pop();
                int tempCount = counts.top();
                counts.pop();

                while(tempCount--) tempString += curr;

                curr = tempString; 
            }

            else{
                curr += s[i];
            }
        }
        return curr;
    }
};