class Solution {
public:

    bool isPossible(vector<int>& position, int n, int m, int minVal){
        int cows = 1, lastCann = position[0];
        for(int i = 1; i < n; i++){
        if((position[i] -lastCann) >= minVal){
            cows++;
            lastCann = position[i];
        }
        if(cows == m) return true;
        }
        return false;
    };

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int st = 1, end = position[position.size() - 1] - position[0], ans = -1;
        
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(isPossible(position, position.size(), m, mid)){
                ans = mid;
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
            
        }
        return ans;
    }
};