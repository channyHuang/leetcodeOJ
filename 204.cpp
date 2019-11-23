class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        if (n == 3) return 1;
        if (n <= 5) return 2;
        bool isNotPri[n] = {0};
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (!isNotPri[i]) {
                res++;
                int j = 2 * i;
                while (j < n) {
                    isNotPri[j] = 1;
                    j += i;
                }
            }
        }
        return res;
    }
    /*int countPrimes(int n) {
        if (n <= 2) return 0;
        if (n == 3) return 1;
        int res = 2;
        for (int i = 5; i < n; i += 2) {
            if (isPri(i)) res++;
        }
        return res;
    }*/

    bool isPri(int n) {
        if (n <= 0) return false;
        if (n <= 3) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i <= n/2 + n%2; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
};
