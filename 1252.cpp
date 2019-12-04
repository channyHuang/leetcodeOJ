class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int rlen = indices.size();
        int rows[n] = {0};
        int cols[m] = {0};
        for (int i = 0; i < rlen; i++) {
            rows[indices[i][0]]++;
            cols[indices[i][1]]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((rows[i] + cols[j]) % 2) res++;
            }
        }
        return res;
    }
};
