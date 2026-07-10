class Solution {
public:
    bool rotateString(string s, string goal) {

        s += s;
        return s.contains(goal);

    }
};