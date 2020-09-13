class Solution {
public:
    char findKthBit(int n, int k) {
        //leni = 2^i - 1
        if (k == 1) return '0';
        if (k <= 4) return '1';

        int len = (1 << n) - 1;
        int mid = (len >> 1) + 1;
        if (k == mid) return '1';
        if (k > mid) {
            int newk = (1 << (n - 1)) - (k - mid);
            return (findKthBit(n - 1,  newk) == '0' ? '1' : '0');
        }
        return findKthBit(n - 1, k);
    }
};
