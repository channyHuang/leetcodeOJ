class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        if (n == 2) return 987;
        long long maxn = pow(10, n) - 1;
        long long minn = pow(10, n - 1);
        long long mulResult = 0;
        for (int i = maxn; i >= minn; i--) {
            mulResult = reverse(i);
            for (int j = maxn; j >= minn; j--) {
                if ((long long)j * j < mulResult) break;
                if (mulResult % j != 0) continue;
                //cout << mulResult << " " << j << endl;
                return mulResult % rest;
            }
        }
        return mulResult % rest;
    }

    long long reverse(int input) {
        long long res = input;
        while (input) {
            int bit = input % 10;
            input /= 10;
            res = res * 10 + bit;
        }
        return res;
    }

private:
    int rest = 1337;
};
