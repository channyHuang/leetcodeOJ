class Solution {
public:
    int reverse(int x) {
        long long maxn = 2147483647;
        long long minn = -2147483648;
        //2^31-1=2147483647,-2^31=-2147483648
        bool minu = false;
        if (x < 0) {
            minu = true;
        }

        if(x <= minn) return 0;
        if (minu) x = -x;

        long long res = 0;
        while (x != 0) {
            if (!minu && res > maxn / 10) return 0;
            if (!minu && res * 10 > maxn - x % 10) return 0;
            if (minu && res > (maxn + 1) / 10) return 0;
            if (minu && res * 10 > (maxn + 1) - x % 10) return 0;
            res = res * 10 + x % 10;
            x = x / 10;
        }

        if (minu) return -res;
        else return res;
    }
};
