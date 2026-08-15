class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0, starCount = 0;

        for(char c : s){
            if(c == '(') openCount++;

            else if(c == '*') starCount++;

            else{
                if(openCount > 0) openCount--;

                else if(starCount > 0) starCount--;

                else return false;
            }
        }

        int closeCount = 0;
        starCount = 0;

        for(int i = s.length() - 1; i >= 0; i--){
            char c = s[i];
            if(c == ')') closeCount++;

            else if(c == '*') starCount++;

            else{
                if(closeCount > 0) closeCount--;

                else if(starCount > 0) starCount--;

                else return false;
            }
        }

        return true;
    }
};