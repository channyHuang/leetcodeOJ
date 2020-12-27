class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int len = customers.size();
        long long lasttime = 0;
        long long waittime = 0;
        for (int i = 0; i < len; i++) {
            if (lasttime <= customers[i][0]) {
                waittime += customers[i][1];
                lasttime = customers[i][0] + customers[i][1];
            } else {
                waittime += (lasttime - customers[i][0]);
                waittime += customers[i][1];
                lasttime += customers[i][1];
            }
        }
        return waittime * 1.0 / len;
    }
};
