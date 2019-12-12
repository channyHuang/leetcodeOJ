class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (valid(i)) res.push_back(i);
        }
        return res;
    }

    bool valid(int n) {
        int m = n;
        int bit = 0;
        while (n) {
            bit = n % 10;
            if (bit == 0) return false;
            if (m % bit != 0) return false;
            n /= 10;
        }
        return true;
    }
};
