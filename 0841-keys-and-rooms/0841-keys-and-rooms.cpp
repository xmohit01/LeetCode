class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> s;
        s.insert(0);

        queue<vector<int>> q;
        q.push(rooms[0]);

        while(!q.empty()){
            for(int i : q.front()){
                if(!s.contains(i)){
                    s.insert(i);
                    q.push(rooms[i]);
                }
            }
            q.pop();
        }
        return s.size() == rooms.size();
    }
};