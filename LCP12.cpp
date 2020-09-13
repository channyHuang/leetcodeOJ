class Solution {
public:
    int minTime(vector<int>& time, int m) {
        int len = time.size();
        if (len == 1 || m >= len) return 0;
        int minn = 0, maxn = 0;
        for (int i = 0; i < len; i++) {
            maxn += time[i];
        }
        int res = maxn;
        while (minn <= maxn) {
            int midn = (minn + maxn) / 2;
            int day = 1;
            int pos = 1;
            int curTime = time[0];
            int curMax = time[0];
            while (pos < len) {
                int tmpMax = max(curMax, time[pos]);
                //new day
                if (curTime + time[pos] - tmpMax > midn) {
                    day++;
                    curTime = time[pos];
                    curMax = time[pos];
                    if (day > m) break;
                } else {
                    curTime += time[pos];
                    curMax = tmpMax;
                }
                pos++;
            }

            if (day > m) {
                minn = midn + 1;
            } else {
                res = min(res, midn);
                maxn = midn - 1;
            }
        }
        return res;
    }
};
