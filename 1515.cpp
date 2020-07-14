class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        int len = positions.size();
        double x = 0, y = 0;
        double l = 0, r = 100;
        for (int i = 0; i <= 100; i++) {
            double mid = (l + r) / 2;
            double midr = (mid + r) / 2;

            double distl = caly(mid, positions);
            double distr = caly(midr, positions);
            if (distl < distr) {
                r = midr;
            } else {
                l = mid;
            }
        }
        x = (l + r) / 2;
        return caly(x, positions);
    }

    double caly(double x, vector<vector<int>>& positions) {
        double l = 0, r = 100;
        for (int i = 0; i <= 100; i++) {
            double mid = (l + r) / 2;
            double midr = (mid + r) / 2;

            double distl = distance(x, mid, positions);
            double distr = distance(x, midr, positions);
            if (distl < distr) {
                r = midr;
            } else {
                l = mid;
            }
        }
        return distance(x, (l + r) / 2, positions);
    }

    double disPoint(double x, double y, int a, int b) {
        return sqrt((x - a) * (x - a) + (y - b) * (y - b));
    }

    double distance(double x, double y, vector<vector<int>>& vec) {
        double res = 0;
        for (int i = 0; i < vec.size(); i++) {
            res += disPoint(x, y, vec[i][0], vec[i][1]);
        }
        return res;
    }
};
