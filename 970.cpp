class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> res;
        if (bound <= 0) return res;
        set<int> sets;
        for (int i = 1; i < bound; i *= x) {
            for (int j = 1; j < bound; j *= y) {
                if (i + j <= bound) sets.insert(i + j);
                else break;
                if (j * y == j) break;
            }
            if (i * x == i) break;
        }
        for (set<int>::iterator itr = sets.begin(); itr != sets.end(); itr++) {
            res.push_back(*itr);
        }
        return res;
    }
};
