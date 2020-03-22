class Solution {
public:
    int findNthDigit(int n) {
        if (n <= 9) return n; //9
        int bit = 2;
        long long base = 10;
        long long num = 90;
        long long lastcount = 9;
        long long count = 189; // 9, 9 + 90 * 2, 9 + 90 * 2 + 900 * 3
        while (1) {
            if (n <= count) {
                int idx = (n - lastcount - 1) / bit;
                int left = (n - lastcount - 1) % bit;
                int res = (base + idx);
                vector<int> bits;
                while (res) {
                    bits.push_back(res % 10);
                    res /= 10;
                }
                return bits[bits.size() - left - 1];
            }
            bit++;
            base *= 10;
            num *= 10;
            lastcount = count;
            count += (num * bit);
        }
        return 0;
    }
};
