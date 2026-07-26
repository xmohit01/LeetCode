class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int val : asteroids){
            if(val >= 0) ans.push_back(val);
            else{
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(val)) ans.pop_back();

                if(!ans.empty() && ans.back() == abs(val)) ans.pop_back();

                else if(ans.empty() || ans.back() < 0) ans.push_back(val);
            }
        }
        return ans;
    }
};