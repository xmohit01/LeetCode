class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int stColor = (start[0] + start[1]) % 2;
        int endColor = (target[0] + target[1]) % 2;

        return stColor == endColor;
    }
};