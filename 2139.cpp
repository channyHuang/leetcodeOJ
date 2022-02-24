class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if (target == 1) return 0;
        int res = 0;
        while (maxDoubles > 0) {
            if (target & 1) {
                res++;
                target--;
            } else {
                target >>= 1;
                maxDoubles--;
                res++;
            }
            if (target == 1) break;
        }
        if (target != 1) {
            res += (target - 1);
        }
        return res;
    }
};
