class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
        if (len <= 1) return len;
        sort(points.begin(), points.end(), cmp);
        int res = 1;
        int minn = points[0][1];
        for (int i = 1; i < len; i++) {
            if (points[i][0] > minn) {
                res++;
                minn = points[i][1];
                continue;
            }
            if (points[i][1] < minn) {
                minn = points[i][1];
            }
        }
        return res;
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
};
