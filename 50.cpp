class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        bool negitive = false;
        if (n == 0) return res;
        if (n < 0) {
            negitive = true;
            if (n == -2147483648) {
                res = x;
                n = 2147483647;
            } else n = -n;
        }
        res *= myPowPositive(x, n);

        if (negitive) res = 1.0 / res;
        return res;
    }

    double myPowPositive(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        int halfn = n / 2;
        double halfres = myPowPositive(x, halfn);
        return halfres * halfres * myPowPositive(x, n & 1);
    }
};