class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int hr = 0, min = 0, sec = 0;
        int hrs = ((endTime[0] - '0') * 10 + (endTime[1] - '0')) - ((startTime[0] - '0') * 10 + (startTime[1] - '0'));

        int mins = ((endTime[3] - '0') * 10 + (endTime[4] - '0')) - ((startTime[3] - '0') * 10 + (startTime[4] - '0'));

        int secs = ((endTime[6] - '0') * 10 + (endTime[7] - '0')) - ((startTime[6] - '0') * 10 + (startTime[7] - '0'));

        return hrs * 3600 + mins * 60 + secs;
    }
};