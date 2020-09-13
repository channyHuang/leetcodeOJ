class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int len = bloomDay.size();
        if (m * k > len) return -1;
        int minn = bloomDay[0], maxn = bloomDay[0];
        for (int i = 1; i < len; i++) {
            minn = min(minn, bloomDay[i]);
            maxn = max(maxn, bloomDay[i]);
        }
        if (m * k == len) return maxn;
        int res = maxn;
        while (minn <= maxn) {
            int midn = (minn + maxn) / 2;
            int stPos = 0;
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (bloomDay[i] > midn) {
                    stPos = i + 1;
                } else if (i - stPos + 1 >= k) {
                    cnt++;
                    if (cnt >= m) break;
                    stPos = i + 1;
                }
            }
            if (cnt >= m) {
                res = midn;
                maxn = midn - 1;
            } else {
                minn = midn + 1;
            }
        }
        return res;
    }
};
