class Solution {
public:
    int addDigits(int num) {
        int m = num;
        while(m >= 10) {
            m = next(m);
        }
        return m;
    }

    int next(int n) {
        int res = 0;
        while (n != 0) {
            res += (n % 10);
            n /= 10;
        }
        return res;
    }
};
