class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == -2147483648 ? 2147483647 : -dividend;
        bool positive = true;
        if (dividend > 0 && divisor < 0) positive = false;
        if (dividend < 0 && divisor > 0) positive = false;
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;
        long long res = div(dividend, divisor);

        return positive ? res : -res;
    }

    long long div(int a, int b) {
        if (a >= 0 || a > b) return 0;
        if (a == b) return 1;
        long long nb = b;
        long long res = 0;
        long long count = 1;
        while (nb > a) {
            a -= nb;
            res += count;
            nb += nb;
            count += count;
        }
        return res + div(a, b); 
    }
};
