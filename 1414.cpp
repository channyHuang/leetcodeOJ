class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        long long f[100];
        f[0] = f[1] = 1;
        for (int i = 2; i < 45; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        //f[44] = 1134903170;
        int i = 44;
        int res = 0;
        while (k) {
            while (f[i] > k) i--;
            if (i == 0 || i == 1) {
                res += k;
                break;
            }
            k -= f[i];
            res++;
        }
        return res;
    }
};
