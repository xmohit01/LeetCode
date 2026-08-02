class Solution {
public:
    int distance(vector<int>& p1, vector<int>& p2){
        int dx = p1[0] - p2[0];
        int dy = p1[1] - p2[1];
        return dx * dx + dy * dy;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int dist1 = distance(p1, p2);
        int dist2 = distance(p1, p3);
        int dist3 = distance(p1, p4);
        int dist4 = distance(p2, p3);
        int dist5 = distance(p2, p4);
        int dist6 = distance(p3, p4);

        unordered_map<int, int> m;
        for(int dist : {dist1, dist2, dist3, dist4, dist5, dist6}){
            m[dist]++;
        }

        if(m.size() != 2) return false;
        bool ans = false;
        for(auto& p : m){
            if(p.first == 0) return false;

            if(p.second != 2 && p.second != 4) return false;
        }

        return true;
    }
};