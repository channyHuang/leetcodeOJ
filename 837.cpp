class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (n >= maxPts + k) return 1;
        if (n < k) return 0;
        vector<double> p(maxPts + k + 1, 0);
        double pro = 1.0f / maxPts;
        for (int i = k; i <= std::min(n, maxPts + k); ++i) {
            p[i] = 1;
        }
        if (k == 0) return p[0];
        p[k - 1] = std::min(n - k + 1, maxPts) * pro;
        for (int i = k - 2; i >= 0; --i) {
            p[i] = p[i + 1] + pro * (p[i + 1] - p[i + 1 + maxPts]);
        }
        return p[0];
    }
};
