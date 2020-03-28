class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len = timeSeries.size();
        if (len <= 0) return 0;
        if (len == 1) return duration;
        int res = 0;
        int stTime = timeSeries[0];
        int endTime = stTime + duration;
        for (int i = 1; i <= len; i++) {
            if (i == len) {
                res += (endTime - stTime);
                break;
            }
            if (timeSeries[i] > endTime) {
                res += (endTime - stTime);
                stTime = timeSeries[i];
                endTime = stTime + duration;
            } else {
                endTime = timeSeries[i] + duration;
            }
        }
        return res;
    }
};
