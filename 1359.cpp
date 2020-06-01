class Solution {
public:
    int countOrders(int n) {
        if (n == 1) return 1;
        if (n == 2) return 6;
        long long res = 2 * n * (2 * n - 1) / 2;
        return (res * countOrders(n - 1)) % 1000000007;
    }
};
