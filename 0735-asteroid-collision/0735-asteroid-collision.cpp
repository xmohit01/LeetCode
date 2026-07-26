class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> s;
        
        for(int i = 0; i < n; i++){
            int val = asteroids[i];
            if(val >= 0) s.push(val);

            else{
                bool cont = false;
                while(!s.empty() && abs(val) >= s.top() && s.top() >= 0){
                    if(!s.empty() && abs(val) == s.top()){
                        s.pop();
                        cont = true;
                        break;
                    }
                    else{
                        s.pop();
                    }
                }
                if(cont) continue;
                if(s.empty() || s.top()/abs(s.top()) == val/abs(val)) s.push(val);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};