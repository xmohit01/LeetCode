class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> R;
        queue<int> D;

        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R') R.push(i);
            else D.push(i);
        }

        while(!R.empty() && !D.empty()) {
            if(R.front() < D.front()) {
                int r = R.front();

                R.pop();
                D.pop();

                R.push(r + n);
            }
            else {
                int d = D.front();

                D.pop();
                R.pop();

                D.push(d + n);
            }
        }

        if(R.empty()) return "Dire";
        else return "Radiant";
    }
};