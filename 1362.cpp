class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> res = {1, num + 1};
        findFactor(num + 1, res[0], res[1], num);
        int minn = 1, maxn = num + 2;
        bool ret = findFactor(num + 2, minn, maxn, res[1] - res[0]);
        if (ret && maxn - minn < res[1] - res[0]) {
            res[0] = minn;
            res[1] = maxn;
        }
        return res;
    }

    bool findFactor(int n, int &minn, int &maxn, int maxdiff) {
        minn = 1;
        maxn = n;
        int endpos = std::sqrt(n);
        for (int i = endpos; i >= 2; --i) {
            if (n % i == 0) {
                minn = i;
                maxn = n / i;
                return true;
            }
            if (i + maxdiff < endpos) return false;
        }
        return false;
    }
};
