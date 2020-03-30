class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int len = points.size();
        sort(points.begin(), points.end(), cmp);
        if (len <= 3) return 0;
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                for (int k = j + 1; k < len; k++) {
                    for (int l = k + 1; l < len; l++) {
                        double midIlX = (points[i][0] + points[l][0]) / 2.0;
                        double midJkX = (points[j][0] + points[k][0]) / 2.0;
                        if (midIlX != midJkX) continue;
                        double midIlY = (points[i][1] + points[l][1]) / 2.0;
                        double midJkY = (points[j][1] + points[k][1]) / 2.0;
                        if (midJkY != midIlY) continue;
                        if (dist(points, i, l) == dist(points, j, k)) {
                            double tmp = sqrt(dist(points, i, j) * dist(points, j, l));
                            if (res == 0) res = tmp;
                            else if (res > tmp) res = tmp;
                        } 
                    }
                }
            }
        }
        return res; 
    }

    double dist(vector<vector<int>>& points, int i, int j) {
        return (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
    }

    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
};
