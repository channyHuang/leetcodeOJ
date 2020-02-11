class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n < 0) return res;
        set<int> resset;
        res.push_back(0);
        resset.insert(0);
        long long len = 1;
        long long total = (1 << n);
        while (len < total) {
            int cur = res[len - 1];
            int mid = 1;
            int next = (cur ^ mid);
            while (resset.find(next) != resset.end()) {
                mid <<= 1;
                next = (cur ^ mid);
            }
            res.push_back(next);
            resset.insert(next);
            len++;
        }
        return res;
    }
};