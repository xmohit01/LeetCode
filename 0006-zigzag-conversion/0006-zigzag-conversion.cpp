class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> vec(numRows);

        int currRow = 0;
        bool direction = false;
        for(char c : s){
            if(direction == false){
                vec[currRow] += c;
                currRow++;

                if(currRow == numRows - 1) direction = true;
            }
            else{
                vec[currRow] += c;
                currRow--;
                
                if(currRow == 0) direction = false;
            }
        }
        
        string ans = "";
        for(auto& v : vec) ans += v;

        return ans;
    }
};