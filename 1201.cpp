class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long stPos = 1, endPos = 2000000000;
        long long ab = minFactor(a, b);
        long long ac = minFactor(a, c);
        long long bc = minFactor(b, c);
        long long abc = minFactor(ab, c);
        while (stPos <= endPos) {
            long long midPos = (stPos + endPos) / 2;
            int cnt = calc(midPos, a, b, c, ab, ac, bc, abc);
            if (cnt < n) stPos = midPos + 1;
            else if (cnt > n) endPos = midPos - 1;
            else {
                if ((midPos % a != 0) && (midPos % b != 0) && (midPos % c != 0)) endPos = midPos - 1;
                else return midPos;
            }
        }
        return 0;
    }

    int calc(int x, int a, int b, int c, long long ab, long long ac, long long bc, long long abc) {
        return x / a + x / b + x / c - x / ab - x / ac - x / bc + x / abc;
    }

    long long maxFactor(long long a, long long b) {
        if (a == b) return a;
        if (a > b) return maxFactor(b, a);
        if (a == 0) return b;
        b %= a;
        return maxFactor(b, a);
    }

    long long minFactor(long long a, long long b) {
        return a * b / maxFactor(a, b);
    }
};
