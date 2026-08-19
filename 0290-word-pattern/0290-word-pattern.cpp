class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> m;
        unordered_set<string> seen;

        int idx = 0;
        for(char c : pattern){
            if(idx >= s.length()) return false;

            string temp = "";
            while(idx < s.length() && s[idx] != ' '){
                temp += s[idx];
                idx++;
            }
            idx++;

            if(m.find(c) != m.end()){
                if(m[c] != temp) return false;
            }
            else{
                if(seen.find(temp) != seen.end()) return false;

                m[c] = temp;
                seen.insert(temp);
            }
        }
        return idx >= s.length();
    }
};