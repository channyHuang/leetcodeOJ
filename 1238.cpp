class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int pos = 0;
        int maxn = (1 << n);
        vector<int> vec(maxn, 0);
        for (int i = 0; i < maxn; i++) {
            vec[i] = (i ^ i >> 1);
            if (vec[i] == start) pos = i;
        }
        vector<int> res(maxn, 0);
        for (int i = 0; i < maxn; i++) {
            res[i] = vec[(i + pos) % maxn];
        }
        return res;
    }
};
