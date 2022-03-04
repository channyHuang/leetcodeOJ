// 溢出处理

class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        if (neededApples <= 0) return 0;
        if (neededApples <= 12) return 8; // a = 1, C = 2 * 4
        long long maxn = std::pow(neededApples, 1.0 / 3) + 1;
        long long minn = 2;
        while (minn <= maxn) {
            if (minn == maxn) return (minn << 3);
            long long mid = ((minn + maxn) >> 1);
            long long s = sum(mid);
            if (s == neededApples) return (mid << 3);
            if (s < neededApples) minn = mid + 1;
            else maxn = mid;
        }
        return minn;
    }
    // x in [-a, a], y in [-b, b], total apples (a = b maxn)
    long long sum(long long a) {
        return 2 * a * (a * (2 * a + 3) + 1);
    }
};
