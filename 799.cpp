class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0) return 0;
        // poured >= 1
        if (query_row == 0) return 1;
        // query_row >= 1
        if (poured == 1) return (query_row == 0 ? 1 : 0);
        const int maxn = 100;
        vector<vector<double>> left(maxn, vector<double>());
        left[0].push_back(poured);
        for (int i = 1; i <= query_row; ++i) {
            left[i].resize(i + 1, 0);
        }
        for (int i = 1; i <= query_row; ++i) {
            bool allzero = true;
            if (left[i - 1][0] > 1) {
                left[i][0] = (left[i - 1][0] - 1) * 0.5;
                allzero = false;
            }
            if (left[i - 1][i - 1] > 1) {
                left[i][i] = (left[i - 1][i - 1] - 1) * 0.5;
                allzero = false;
            }
            for (int j = 1; j <= (i >> 1); ++j) {
                if (left[i - 1][j] > 1) {
                    left[i][j] += (left[i - 1][j] - 1) * 0.5;
                    allzero = false;
                }
                if (left[i - 1][j - 1] > 1) {
                    left[i][j] += (left[i - 1][j - 1] - 1) * 0.5;
                    allzero = false;
                }

                left[i][i - j] = left[i][j];
            }
            if (allzero) break;
        }

        return (left[query_row][query_glass] >= 1 ? 1 : left[query_row][query_glass]);
    }
};
