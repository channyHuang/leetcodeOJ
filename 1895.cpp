class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> rowsum(rows + 1, vector<int>(cols, 0));
        vector<vector<int>> colsum(rows, vector<int>(cols + 1, 0));
        vector<vector<int>> leftright(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> rightleft(rows + 1, vector<int>(cols + 1, 0));
        int res = 1;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                rowsum[i + 1][j] = grid[i][j] + rowsum[i][j];
                colsum[i][j + 1] = grid[i][j] + colsum[i][j];
                leftright[i + 1][j + 1] = grid[i][j] +  leftright[i][j];
                rightleft[i + 1][j] = grid[i][j] + rightleft[i][j + 1];
            }
        }
        for (int i = rows - 1; i >= 1; --i) {
            for (int j = cols - 1; j >= 1; --j) {
                int maxl = std::min(i, j);
                for (int l = maxl; l >= res; l--) {
                    int sum = rowsum[i + 1][j] - rowsum[i - l][j];
                    int idx = 0;
                    for (idx = 0; idx <= l; idx++) {
                        if (rowsum[i + 1][j - idx] - rowsum[i - l][j - idx] != sum) break;
                        if (colsum[i - idx][j + 1] - colsum[i - idx][j - l] != sum) break;
                    }
                    if (idx <= l) continue;
                    if (leftright[i + 1][j + 1] - leftright[i - l][j - l] != sum) continue;
                    if (rightleft[i + 1][j - l] - rightleft[i - l][j + 1] != sum) continue;
                    res = l + 1;
                    break;
                }
            }
        }
        return res;
    }
};
