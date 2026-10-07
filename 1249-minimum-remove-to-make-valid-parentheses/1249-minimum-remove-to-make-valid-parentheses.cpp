class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int removeOpen = 0, removeClose = 0;
        int opens = 0;

        for(char c : s) {
            if(c == '(') {
                removeOpen++;
                opens++;
            }
            else if(c == ')') {
                if(removeOpen > 0) removeOpen--;
                else removeClose++;
            }
        }

        int open = 0;
        string result;
        for(char c : s) {
            if(c == '(') {
                if(open == opens - removeOpen) {
                    continue;
                }
                
                result.push_back(c);
                open++;
            }
            else if(c == ')') {
                if(removeClose > 0) {
                    removeClose--;
                    continue;
                }

                result.push_back(c);
            }
            else {
                result.push_back(c);
            }
        }

        return result;
    }
};