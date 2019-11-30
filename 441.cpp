class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 0) return 0;
        if (n <= 2) return 1;
        int res = 0;
        while (n >= 0) {
            res++;
            n -= res;
        }
        return res - 1;
    }
};
