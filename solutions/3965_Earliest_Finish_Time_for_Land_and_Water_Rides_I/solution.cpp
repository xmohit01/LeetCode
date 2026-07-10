class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;

        for(int i = 0; i < landStartTime.size(); i++){
            for(int j = 0; j < waterStartTime.size(); j++){
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStartT = max(landFinish, waterStartTime[j]);
                int t1 = waterStartT + waterDuration[j];

                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStartT = max(waterFinish, landStartTime[i]);
                int t2 = landStartT + landDuration[i];

                ans = min(ans, min(t1, t2));
            }
        }
        return ans;
    }
};