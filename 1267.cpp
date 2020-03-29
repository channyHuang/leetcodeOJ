class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows <= 0) return 0;
        int cols = grid[0].size();
        if (cols <= 0) return 0;
        int cntRows[rows], cntCols[cols];
        memset(cntRows, 0, sizeof(cntRows));
        memset(cntCols, 0, sizeof(cntCols));
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) continue;
                count++;
                if (cntRows[i] != 0) cntRows[i] = -1; 
                else cntRows[i] = j + 1;
                if (cntCols[j] != 0) cntCols[j] = -1;
                else cntCols[j] = i + 1;
            }
        }
        int alone = 0;
        for (int i = 0; i < rows; i++) {
            if (cntRows[i] <= 0) continue;
            if (cntCols[cntRows[i] - 1] <= 0) continue;
            alone++;
        }
        return count - alone;
    }
};
