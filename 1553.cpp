class Solution {
public:
    int minDays(int n) {
        if (n <= 2) return n;
        if (n == 3) return 2;

        itr = maps.find(n);
        if (itr != maps.end()) return itr->second;

        maps[n] = std::min(n % 2 + 1 + minDays(n / 2), n % 3 + 1 + minDays( n / 3));
        return maps[n];
    }

private:
    std::map<int, int> maps;
    std::map<int, int>::iterator itr;
};
