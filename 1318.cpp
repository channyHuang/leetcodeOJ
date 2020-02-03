class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while (c) {
            switch(c & 1) {
                case 0:
                    if (a & 1) res++;
                    if (b & 1) res++;
                    break;
                case 1:
                    if (!(a & 1) && !(b & 1)) res++;
                    break;
                default:
                    break;
            }
            c >>= 1;
            b >>= 1;
            a >>= 1;
        }
        while (a) {
            if (a & 1) res++;
            a >>= 1;
        }
        while (b) {
            if (b & 1) res++;
            b >>= 1;
        }
        return res;
    }
};