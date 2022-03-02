// 当n>N(约6000)时，结果接近于1 (N由二分尝试得知) 

class Solution {
public:
    double soupServings(int n) {
        int ca = n / 25 + (n % 25 == 0 ? 0 : 1);
        if (n >= 6000) return 1;
        return search(ca, ca);
    }

    double search(int m, int n) {
        if (m <= 0 && n <= 0) { return 0.5; }
        if (m <= 0) { return 1; }
        if (n <= 0) { return 0; }
        double value[4];
        auto itr = maps.find(pair<int, int>(m - 4, n));
        value[0] = (itr == maps.end() ? search(m - 4, n) : itr->second);
        itr = maps.find(make_pair(m - 3, n - 1));
        value[1] = (itr == maps.end() ? search(m - 3, n - 1) : itr->second);
        itr = maps.find(make_pair(m - 2, n - 2));
        value[2] = (itr == maps.end() ? search(m - 2, n - 2) : itr->second);
        itr = maps.find(make_pair(m - 1, n - 3));
        value[3] = (itr == maps.end() ? search(m - 1, n - 3) : itr->second);
        double res = 0.25 * (value[0] + value[1] + value[2] + value[3]);
        maps[make_pair(m, n)] = res;
        return res;
    }

private:
    map<pair<int, int>, double> maps;
};
