class Solution {
public:
    int maxDiff(int num) {
        vector<int> vec(10, 0);
        int tmp = num;
        int pos = 0;
        while (tmp) {
            vec[pos++] = tmp % 10;
            tmp /= 10;
        }
        vector<int> maxn = vec;
        int x = 9;
        for (int i = pos - 1; i >= 0; i--) {
            if (x == 9) {
                x = maxn[i];
                maxn[i] = 9;
            } else if (maxn[i] == x) {
                maxn[i] = 9;
            }
        }
        vector<int> minn = vec;
        if (minn[pos - 1] != 1) {
            x = minn [pos - 1];
            minn[pos - 1] = 1;
            for (int i = pos - 1; i >= 0; i--) {
                if (minn[i] == x) minn[i] = 1;
            }
        } else {
            x = 0;
            for (int i = pos - 1; i >= 0; i--) {
                if (x == 0) {
                    if (minn[i] == 0 || minn[i] == 1) continue;
                    x = minn[i];
                    minn[i] = 0;
                } else {
                    if (minn[i] == x) minn[i] = 0;
                }
            }
        }
        int maxnum = 0, minnum = 0;
        for (int i = pos - 1; i >= 0; i--) {
            maxnum = maxnum * 10 + maxn[i];
            minnum = minnum * 10 + minn[i];
        }
        return maxnum - minnum;
    }
};
