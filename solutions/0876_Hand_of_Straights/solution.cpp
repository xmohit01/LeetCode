class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int, int> m;
        for(int i = 0; i < n; i++) m[hand[i]]++;

        for(auto& p : m){
            while(p.second--){
                for(int i = p.first + 1; i < p.first + groupSize; i++){
                    if(m[i] == 0) return false;

                    m[i]--;
                }
            }
        }
        return true;
    }
};