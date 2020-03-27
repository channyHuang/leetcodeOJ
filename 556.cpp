class Solution {
public:
    int nextGreaterElement(int n) {
        if (n < 10) return -1;
        vector<int> bits;
        while (n) {
            bits.push_back(n % 10);
            n /= 10;
        }

        int len = bits.size();
        int stPos = -1;
        for (int i = 1; i < len; i++) {
            if (bits[i] < bits[i - 1]) {
                stPos = i;              
                break;
            }
        }
        if (stPos == -1) return -1;
        int idx = stPos - 1;
        for (int i = 0; i < stPos; i++) {
            if (bits[i] <= bits[stPos]) continue;
            if (bits[i] < bits[idx]) idx = i;
        }
        int tmp = bits[idx];
        bits[idx] = bits[stPos];
        bits[stPos] = tmp;
        sort(bits.begin(), bits.begin() + stPos, greater<int>());

        long long res = 0;
        long long base = 1;
        for (int i = 0; i < len; i++) {
            res += (bits[i] * base);
            base *= 10;
        }
        
        if (res > 2147483647) return -1;
        return res;
        return 0;
    }
};
