class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int parent[205] = {0};
        memset(parent, 0, sizeof(parent));
        int len = M.size();
        if (len <= 0) return 0;
        int res = len;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (M[i][j]) {
                    int pi = findParent(parent, i + 1); 
                    int pj = findParent(parent, j + 1);
                    if ((pi == 0) && (pj == 0)) {
                        parent[i + 1] = i + 1;
                        parent[j + 1] = i + 1;
                        res--;
                    } else if (pi == 0) {
                        parent[i + 1] = pj;
                        res--;
                    } else if (pj == 0) {
                        parent[j + 1] = pi;
                        res--;
                    } else if (pi != pj) {
                        parent[pi] = pj;
                        res--;
                    }
                }
            }
        }
        return res;
    }

    int findParent(int parent[205], int n) {
        if (parent[n] == 0) return 0;
        if (parent[n] == n) return n;
        int res = parent[n];
        while (parent[res] != res) res = parent[res];
        return res;
    }
};
