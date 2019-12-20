class Solution {
public:
    bool divisorGame(int N) {
        bool res[1005];
        memset(res, false, sizeof(res));
        res[2] = true;
        res[4] = true;

        vector<int> factors;
        for (int i = 6; i <= N; i++) {
            if (!res[i - 1]) {
                res[i] = true;
                continue;
            }
            if (i % 2 == 0) {
                if (!res[i - 2]) res[i] = true;
            }
            for (int j = 3; j <= (i >> 1); j++) {
                if (i % j != 0) continue;
                if (!res[i - j]) res[i] = true;
            }
            res[i] = false;
        }
        return res[N];
    }
};
