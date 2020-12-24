class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) return 3;
        if (n == 2) return 8;

        vector<long long> dpL(n + 1, 0);
        vector<long long> dpP(n + 1, 0);

        dpL[1] = 1;
        dpP[1] = 1;
        dpL[2] = 2;
        dpP[2] = 2;
        for (int i = 3; i <= n; i++) {
            dpL[i] = (dpP[i - 2] + dpP[i - 1]) % maxn;
            dpP[i] = (dpL[i - 1] + dpP[i - 1]) % maxn;
        }
        long long res = (dpL[n] + dpP[n]) % maxn + 2 * (dpL[n - 1] + dpP[n - 1]) % maxn;
        res %= maxn;
        for (int i = 2; i < n; i++) {
            res += ((dpL[i - 1] + dpP[i - 1]) % maxn) * ((dpL[n - i] + dpP[n - i]) % maxn);
            res %= maxn;
        }
        return res;
    }
private:
    int maxn = 1000000007;
};
