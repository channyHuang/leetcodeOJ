class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int len = intervals.size();
        vector<int> res;
        if (len <= 0) return res;
        if (len == 1) {
            res.push_back(-1);
            return res;
        }
        res.resize(len);
        vector<vector<int>> sortInt = intervals;
        for (int i = 0; i < len; i++) sortInt[i].push_back(i);
        sort(sortInt.begin(), sortInt.end(), cmp);
        for (int i = 0; i < len; i++) {
            int target = intervals[i][1];
            int idx = -1;
            int st = 0;
            int end = len - 1;
            while (st <= end) {
                int mid = (st + end) / 2;
                if (sortInt[mid][0] < target) {
                    st = mid + 1;
                } else {
                    idx = mid;
                    end = mid - 1;
                }
            }
            if (idx == -1) res[i] = -1;
            else res[i] = sortInt[idx][2];
        }
        return res;
    }
};
