class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        len = strs.size();
        slen = strs[0].length();

        vector<int> parents(len, 0);

        for (int i = 1; i < len; i++) {
            parents[i] = i;
            for (int j = 0; j < i; j++) {
                if (!isSimilar(strs[i], strs[j])) continue;
                if (parents[i] == i) {
                    parents[i] = j;
                } else {
                    int pj = getParent(parents, j);
                    int pi = getParent(parents, i);
                    if (pi < pj) {
                        parents[pj] = pi;
                    } else if (pi > pj) {
                        parents[pi] = pj;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (parents[i] == i) {
                res++;
            }
        }
        return res;
    }

    int getParent(vector<int>& parents, int idx) {
        while (parents[idx] != idx) {
            idx = parents[idx];
        }
        return idx;
    }

    bool isSimilar(string& a, string& b) {
        int index = -1;
        bool hasTwoDiff = false;
        for (int i = 0; i < slen; i++) {
            if (a[i] == b[i]) continue;
            if (index == -1) {
                index = i;
                continue;
            }
            if (hasTwoDiff) {
                return false;
            }
            if (a[i] != b[index] || b[i] != a[index]) {
                return false;
            }
            hasTwoDiff = true;
        }
        if (index == -1 || hasTwoDiff) return true;
        return false;
    }

private:
    int len;
    int slen;
};
