class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int len = points.size();
        int res = 0;
        for (int i = 1; i < len; i++) {
            res += dist(points, i, i - 1);
        }
        return res;
    }

    int dist(vector<vector<int>>& points, int i, int j) {
        int x = abs(points[i][0] - points[j][0]);
        int y = abs(points[i][1] - points[j][1]);
        if (x == y) return x;
        return min(x, y) + abs(x - y);
    }
};
