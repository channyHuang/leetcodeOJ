class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;

        std::set<int> num;
        num.insert(n);
        int m = n;
        while (1) {
            m = next(m);
            if (m == 1) return true;
            if (num.find(m) != num.end()) return false;
            num.insert(m);
        }
    }

    int next(int n) {
        int res = 0;
        while (n != 0) {
            res += (n%10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};
