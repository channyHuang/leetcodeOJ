class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (len <= 1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int lastEnd = intervals[0][1];
        int res = 0;
        for (int i = 1; i < len; i++) {
            if (intervals[i][0] >= lastEnd) {
                lastEnd = intervals[i][1];
                continue;
            }
            res++;
            if (intervals[i][1] >= lastEnd) continue;
            lastEnd = intervals[i][1];
        }
        return res;
    }

    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
};
