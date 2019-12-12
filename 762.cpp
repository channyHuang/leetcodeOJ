class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; i++) {
            int tmp = count(i);
            if (valid(tmp)) res++;
        }
        return res;
    }

    int count(int n) {
        int res = 0;
        while (n) {
            n &= (n - 1);
            res += 1;
        }
        return res;
    }

    bool valid(int n) {
        if (n == 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i <= n / 2; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
};
