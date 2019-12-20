class Solution {
public:
    int bitwiseComplement(int N) {
        int bit = 0;
        int res = 0;
        if (N == 0) return 1;
        while (N) {
            if ((N & 1) == 0) {
                res += (1 << bit);
            }
            bit++;
            N >>= 1;
        }
        return res;
    }
};
