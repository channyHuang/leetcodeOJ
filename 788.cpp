class Solution {
public:
    int rotatedDigits(int N) {
        if (N <= 1) return 0;
        int res = 1;
        for (int i = 3; i <= N; i++) {
            int x = i;
            bool valid = true;
            bool same = true;
            while (x) {
                int tmp = x % 10;
                x /= 10;
                if (tmp == 0 || tmp == 1 || tmp == 8) continue;
                if (tmp == 2 || tmp == 5 || tmp == 6 || tmp == 9) {
                    same = false;
                }
                else {
                    valid = false;
                    break;
                }
            }
            if (valid && (!same)) res++;
        }
        return res;
    }
};
