class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        return sum(num) == num ? true : false;
    }

    int sum(int n) {
        int res = 1;
        int maxn = n;
        for (int i = 2; i <  maxn; i++) {
            if (n % i == 0) {
                res += i;
                int t = n / i;
                if (t != i) res += t;
                if (t < maxn) maxn = t;
            }
        }
        return res;
    }
};
