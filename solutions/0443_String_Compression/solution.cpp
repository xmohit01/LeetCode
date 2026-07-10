class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int n = chars.size();
        for(int i = 0; i < n; ){
            char ch = chars[i];
            int count = 0;
            while(i < n && chars[i] == ch){
                i++;
                count++;
            }
            if(count == 1) chars[idx++] = ch;
            else{
                chars[idx++] = ch;
                string str = to_string(count);
                for(char dig : str) chars[idx++] = dig;
            }
        }
        return idx;
    }
};