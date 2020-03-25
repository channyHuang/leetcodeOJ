class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        long long x = n;
        while (x != 1) {
            if (x & 1) {
                if ((x & 2) && x != 3) x++;
                else x--;
                res++;
                if (x == 1) break;
                x >>= 1;
                res++;
            } else {
                x >>= 1;
                res += 1;
            }
        }
        return res;
    }
};
