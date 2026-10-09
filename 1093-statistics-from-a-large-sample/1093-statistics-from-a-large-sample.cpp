class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double mode;
        int highest = 0;

        int len = 0;

        double mean = 0;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0; i < 256; i++) len += count[i];

        for(int i = 255; i >= 0; i--) {
            if(count[i] != 0) {
                if(maxi == INT_MIN) maxi = i;

                mini = i;

                mean += (1.0 * i / len) * count[i];

                if(count[i] > highest) {
                    mode = i;
                    highest = count[i];
                }
            }
        }
        
        double median = -1;

        int curr = 0;

        for(int i = 0; i < 256; i++) {
            if(count[i] != 0) {
                curr += count[i];

                if(len % 2 == 1 && curr > len / 2) {
                    median = i;
                    break;
                }

                if(len % 2 == 0) {
                    if(curr == len / 2) median = i;

                    if(curr > len / 2) {
                        if(median != -1) median = (median + i) / 2.0;

                        else median = (2 * i) / 2.0;

                        break;
                    }
                }
            }
        }

        return {(double)mini, (double)maxi, mean, median, mode};
    }
};