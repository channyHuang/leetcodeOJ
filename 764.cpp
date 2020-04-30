class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<bool>> maps;
        vector<vector<int>> rows;
        vector<vector<int>> cols;
        if (mines.size() >= N * N) return 0;
        for (int i = 0; i < N; i++) {
            vector<bool> sub(N, true);
            maps.push_back(sub);
            vector<int> rsub(N, 0);
            rows.push_back(rsub);
            vector<int> csub(N, 0);
            cols.push_back(csub);
        }
        for (int i = 0; i < mines.size(); i++) {
            maps[mines[i][0]][mines[i][1]] = false;
        }
        for (int i = 0; i < N; i++) {
            rows[i][0] = (maps[i][0] ? 1 : 0);
            cols[0][i] = (maps[0][i] ? 1 : 0);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!maps[i][j]) continue;
                if (j > 0) rows[i][j] = rows[i][j - 1] + 1;
                if (i > 0) cols[i][j] = cols[i - 1][j] + 1;
            }
        }
        int res = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < N; j++) {
                if (!maps[i][j]) continue;
                if (i + res >= N || j + res >= N) break;
                if (i - res < 0 || j - res < 0) continue;
                if (rows[i][j + res] >= (res * 2 + 1) && cols[i + res][j] >= (res * 2 + 1)) {
                    res++;
                    j--;
                }
            }
            if (i + res >= N) break;
        }
        return res;
    }
};
