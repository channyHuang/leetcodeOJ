class Solution {
public:
    int findKthNumber(int n, int k) {
        //1 ≤ k ≤ n ≤ 10^9
        if (k == 1) return 1;
        if (n < 10) {
            return k;
        }

        long long prefix = 1;
        while (prefix < n) {
            long long tmp = Count(prefix, n);
            if (tmp < k) {
                k -= tmp;
                prefix += 1;
            } else {
                k--;
                if (k == 0) break;
                prefix *= 10;
            }
        }

        return prefix;
    }

    long long Count(int prefix, int n) {
        long long st = prefix;
        long long end = prefix + 1;
        long long res = 0;
        while (end < n) {
            res += (end - st);
            st *= 10;
            end *= 10;
        }
        if (st <= n) {
            res += (n - st + 1);
        }
        return res;
    }
};