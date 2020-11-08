class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int plen = points.size();
        set<int> sets;
        for (int i = 0; i < plen; i++) {
            sets.insert(points[i][0]);
        }
        int res = 0;
        for (set<int>::iterator itr = sets.begin(); itr != sets.end(); itr++) {
            set<int>::iterator nitr = itr;
            nitr++;
            if (nitr == sets.end()) break;
            res = max(res, *nitr - *itr);
        }
        return res;
    }
};
