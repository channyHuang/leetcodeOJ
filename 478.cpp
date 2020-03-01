class Solution {
public:
    double xc, yc, r;

    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;
    }
    
    vector<double> randPoint() {
        double x = 2.0;
        double y = 2.0;
        while (x * x + y * y > 1) {
            x = 2.0 * (double)rand() / RAND_MAX - 1;
            y = 2.0 * (double)rand() / RAND_MAX - 1;
        }
        vector<double> res;
        res.push_back(x * r + xc);
        res.push_back(y * r + yc);
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
