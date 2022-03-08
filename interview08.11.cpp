class Solution {
public:
    int waysToChange(int n) {
        if (n <= 4) return 1;
        if (n <= 9) return 2;
        long long res = 0;
        // 25, 10, 5, 1
        return subsearch(n, 4);
    }

    long long subsearch(int n, int c) {
        //if (c == 1) return 1;
        //if (c == 2) return n / 5 + 1;
        if (c == 3) {
            long long res = n / 5 + 1; //f(n, 2)
            long long k = n / 10;
            res += k;
            long long stop = (n - 10) / 5;
            long long start = (n - k * 10) / 5;
            res += (start + stop) * ((stop - start) / 2 + 1) / 2;
            res %= maxn;
            return res;
        }
        // c = 4
        long long res = subsearch(n, 3);
        for (int i = 25; i <= n; i += 25) {
            res += subsearch(n - i, 3);
            res %= maxn;
        }
        return res;
    }

private:
    int maxn = 1000000007;
};
