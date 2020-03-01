class Solution {
public:
    int bulbSwitch(int n) {
        if (n <= 0) return 0;
        if (n == 1) return n;
        if (n == 2) return n / 2 + n % 2;
        int res = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = sqrt(i);
            if (tmp * tmp == i) res++;
        }
        return res;
    }
};
