class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        while(x > 0 && y > 0){
            if((x & 1) != (y & 1)) ans++;
            x = x >> 1;
            y = y >> 1;
        }
        while(x > 0){
            if(x & 1) ans++;
            x = x >> 1;
        }
        while(y > 0){
            if(y & 1) ans++;
            y = y >> 1;
        }
        return ans;
    }
};