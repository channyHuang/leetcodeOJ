class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0) return 0;
        if (m == n) return m;
        int res = m;
        while (res && n) {
            res = res & n;
            n = n & (n - 1);
            if (n <= m) break;
        }
        return res;
    }
};
