class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        if (n == 2) return 91;

        long long res[n + 5] = {0};
        res[0] = 2;
        res[1] = 11;
        res[2] = 91;
        //
        //res[3] = 739;
        //res[4] = 5275;
        long long tmp = 81;
        int idx = 8;
        for (int i = 3; i <= n; i++) {
            if (i >= 11) {
                res[i] = res[i - 1];
                continue;
            }
            tmp *= idx;
            idx--;
            res[i] = res[i - 1] + tmp;
        }
        return res[n];
    }
};
