class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int len = points.size();
        set<int> sets;
        for (int i = 0; i < len; i++) {
            sets.insert(points[i][0] * 40000 + points[i][1]);
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (points[i][0] == points[j][0] || points[i][1] == points[j][1]) continue;
                int target1 = points[i][0] * 40000 + points[j][1];
                int target2 = points[j][0] * 40000 + points[i][1];
                if (sets.find(target1) == sets.end() || sets.find(target2) == sets.end()) continue;
                int area = (points[i][0] - points[j][0]) * (points[i][1] - points[j][1]);
                if (area < 0) area = -area;
                if (res == 0) res = area;
                else res = min(res, area);
            }
        }
        return res;
    }
};
