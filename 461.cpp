class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        /*
        while (x && y) {
            if ((x & 1) != (y & 1)) res++;
            x >>= 1;
            y >>= 1;
        }
        while (x) {
            if (x & 1) res++;
            x >>= 1;
        }
        while (y) {
            if (y & 1) res++;
            y >>= 1;
        }
        return res;
        */

        int z = x ^ y;
        while (z) {
            res++;
            z &= (z - 1);
        }
        return res;
    }
};
