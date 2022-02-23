class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int len = fronts.size();
        int res = 2001;
        unordered_set<int> same;
        for (int i = 0; i < len; ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }
        for (int i = 0; i < len; ++i) {
            if (fronts[i] == backs[i]) continue;
            int minn = std::min(fronts[i], backs[i]);
            int maxn = std::max(fronts[i], backs[i]);
            if (res > minn) {
                if (same.find(minn) == same.end()) {
                    res = minn;
                } else if (res > maxn) {
                    if (same.find(maxn) == same.end()) {
                        res = maxn;
                    }
                }
            }
        }
        return (res == 2001 ? 0 : res);
    }
};
