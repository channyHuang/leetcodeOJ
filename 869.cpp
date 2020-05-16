class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int cnt[31][10];
        memset(cnt, 0, sizeof(cnt));
        int sum = 1;
        cnt[0][1] = 1;
        for (int i = 1; i <= 30; i++) {
            sum *= 2;
            int tmp = sum;
            while (tmp) {
                cnt[i][tmp % 10]++;
                tmp /= 10;
            }
        }
        int count[10] = {0};
        while (N) {
            count[N % 10]++;
            N /= 10;
        }
        for (int i = 0; i <= 30; i++) {
            int j;
            for (j = 0; j < 10; j++) {
                if (count[j] != cnt[i][j]) break;
            }
            if (j >= 10) return true;
        }
        return false;
    }
};
