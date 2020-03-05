class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        int res[n + 5] = {0};
        
        res[2] = 1;
        res[3] = 2;
        res[4] = 4;
        for (int i = 5; i <= n; i++) {
            res[i] = i - 1;
            for (int j = 2; j <= i / 2; j++) {
                int tmp = i - j;
                if (res[tmp] > tmp) tmp = res[tmp]; 
                res[i] = max(res[i], j * tmp);
            }
        }
        return res[n];
    }
};
