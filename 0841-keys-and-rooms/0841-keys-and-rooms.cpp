class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> s(rooms.size(), 0);
        s[0] = 1;

        queue<vector<int>> q;
        q.push(rooms[0]);

        while(!q.empty()){
            for(int i : q.front()){
                if(s[i] == 0){
                    s[i] = 1;
                    q.push(rooms[i]);
                }
            }
            q.pop();
        }
        int count = 0;
        for(int i : s) count += i;

        return count == rooms.size();
    }
};