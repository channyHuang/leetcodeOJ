class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = intervals.size();
        vector<vector<int>> res;
        if (len == 0) {
            res.push_back(newInterval);
            return res;
        }
        bool found = false;
        for (int i = 0; i < len; i++) {
            if (found) {
                if (intervals[i][0] > res[res.size() - 1][1]) {
                    res.push_back(intervals[i]);
                } else res[res.size() - 1][1] = max(res[res.size() - 1][1], intervals[i][1]);
                continue;
            }
            //insert before i
            if (intervals[i][0] > newInterval[1]) {
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                found = true;
                continue;
            }
            //insert after i
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
                continue;
            }
            //has connection
            intervals[i][0] = min(intervals[i][0], newInterval[0]);
            intervals[i][1] = max(intervals[i][1], newInterval[1]);
            res.push_back(intervals[i]);
            found = true;
        }
        if (!found) res.push_back(newInterval);
        return res;
    }
};
