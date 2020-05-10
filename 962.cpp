class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int len = A.size();
        int res = 0;
        vector<pair<int, int>> vec;
        for (int i = 0; i < len; i++) {
            vec.push_back(pair<int, int>(A[i], i));
        }
        sort(vec.begin(), vec.end(), cmp);
        int maxn = vec[len - 1].second;
        for (int i = len - 2; i >= 0; i--) {
            res = max(res, maxn - vec[i].second);
            maxn = max(maxn, vec[i].second);
        }
        return res;
    }

    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};
