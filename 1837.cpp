class Solution {
public:
    int sumBase(int n, int k) {
        int res = 0;
        while (n) {
            int rest = n % k;
            res += rest;
            n -= rest;
            n /= k;
        }
        return res;
    }
};
