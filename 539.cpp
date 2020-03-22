class Solution {
public:
    static bool cmp(const string& a, const string& b) {
        if (a[0] == b[0] && a[1] == b[1] && a[3] == b[3]) return a[4] < b[4];
        if (a[0] == b[0] && a[1] == b[1]) return a[3] < b[3];
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end(), cmp);
        int len = timePoints.size();
        int res = diff(timePoints[len - 1], timePoints[0]);
        if (1440 - res < res) res = 1440 - res;
        for (int i = 1; i < len; i++) {
            int tmp = diff(timePoints[i], timePoints[i - 1]);
            if (res > tmp) res = tmp;
        }
        return res;
    }

    int diff(string a, string b) {
        int ha = a[0] * 10 + a[1];
        int hb = b[0] * 10 + b[1];
        int ma = a[3] * 10 + a[4];
        int mb = b[3] * 10 + b[4];
        return ha * 60 + ma - hb * 60 - mb;
    }
};
