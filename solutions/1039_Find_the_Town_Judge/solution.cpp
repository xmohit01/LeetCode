class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n + 1, 0);

        for(int i = 0; i < trust.size(); i++){
            int trustedBy = trust[i][0];
            int trusted = trust[i][1];

            trustCount[trustedBy]--;
            trustCount[trusted]++;
        }

        for(int i = 1; i <= n; i++){
            if(trustCount[i] == n - 1) return i;
        }
        return -1;
    }
};