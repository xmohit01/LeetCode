class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for(int sample = num1; sample <= num2; sample++){

                int n = to_string(sample).length();
                string samplee = to_string(sample);
                for(int i = 1; i < n - 1; i++){
                    if(samplee[i] > samplee[i-1] && samplee[i] > samplee[i+1]) ans++;
                    if(samplee[i] < samplee[i-1] && samplee[i] < samplee[i+1]) ans++;
            }
        }
        return ans;
    }
};