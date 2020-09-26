class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<long long>> dpmax(rows, vector<long long>(cols, INT_MIN));
        vector<vector<long long>> dpmin(rows, vector<long long>(cols, INT_MAX));
        dpmax[0][0] = grid[0][0];
        dpmin[0][0] = grid[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 && j == 0) continue;
                if (i > 0) {
                    dpmax[i][j] = max(dpmax[i - 1][j] * grid[i][j], dpmax[i][j]);
                    dpmax[i][j] = max(dpmin[i - 1][j] * grid[i][j], dpmax[i][j]);
                    dpmin[i][j] = min(dpmin[i - 1][j] * grid[i][j], dpmin[i][j]);
                    dpmin[i][j] = min(dpmax[i - 1][j] * grid[i][j], dpmin[i][j]);
                }
                if (j > 0) {
                    dpmax[i][j] = max(dpmax[i][j - 1] * grid[i][j], dpmax[i][j]);
                    dpmax[i][j] = max(dpmin[i][j - 1] * grid[i][j], dpmax[i][j]);
                    dpmin[i][j] = min(dpmin[i][j - 1] * grid[i][j], dpmin[i][j]);
                    dpmin[i][j] = min(dpmax[i][j - 1] * grid[i][j], dpmin[i][j]);
                }
            }
        }
        long long res = max(dpmax[rows - 1][cols - 1], dpmin[rows - 1][cols - 1]);
        if (res < 0) return -1;
        return res % maxn;
    }
private:
    int rows, cols;
    int maxn = 1000000007;
};
