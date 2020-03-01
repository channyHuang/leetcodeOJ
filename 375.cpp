class Solution {
public:
    int getMoneyAmount(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        if (n <= 10) return ((n - 2) << 1);
        int count[n + 2][n + 2] = {0};
        //i <= j
        for (int i = 1; i <= n; i++) {
            count[i][i] = 0;
            if (i > 1) count[i - 1][i] = i - 1;
            if (i > 2) count[i - 2][i] = i - 1;
        }
        int maxn = (n + 1) / 2 * n;
        for (int j = 3; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (i + j > n) break;
                count[i][i + j] = maxn;
                for (int k = i; k <= i + j; k++) {
                    int tmp = k;
                    int left = 0, right = 0;
                    if (k - 1 >= i) left = count[i][k - 1];
                    if (k + 1 <= i + j) right = count[k + 1][i + j];
                    tmp += max(left, right);
                    if (count[i][i + j] > tmp) count[i][i + j] = tmp;
                }
            }
        }
        return count[1][n];
    }
};
