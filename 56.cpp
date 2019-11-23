class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() <= 0) return res;
        //sort(intervals.begin(), intervals.end(), cmp);
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].size() <= 1) continue;
            vector<int> subres;
            if (res.size() == 0) {
                subres.push_back(intervals[i][0]);
                subres.push_back(intervals[i][1]);
                res.push_back(subres);
                continue;
            }
            if (intervals[i][0] <= res[res.size() - 1][1]) {
                if (res[res.size() - 1][1] < intervals[i][1]) res[res.size() - 1][1] = intervals[i][1];
            } else {
                subres.push_back(intervals[i][0]);
                subres.push_back(intervals[i][1]);
                res.push_back(subres);
            }
        }
        return res;
    }

    static bool cmp(vector<int> a, vector<int> b) {
        if (a.size() == 0 || b.size() == 0) return 0;
        return a[0] <= b[0];
    }
};
