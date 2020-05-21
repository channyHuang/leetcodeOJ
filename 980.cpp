class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();  
        int block = 0;     
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == -1) block++;
                else if (grid[i][j] == 1) {
                    strow = i;
                    stcol = j;
                } else if (grid[i][j] == 2) {
                    endrow = i;
                    endcol = j;
                }
            }
        }
        bool used[20][20];
        memset(used, 0, sizeof(used));
        res = 0;
        pathcnt = rows * cols - block;
        search(grid, used, strow, stcol, 1);
        return res;
    }

    void search(vector<vector<int>>& grid, bool used[20][20], int currow, int curcol, int cnt) {
        used[currow][curcol] = true;
        if (grid[currow][curcol] == 2) {
            if (cnt == pathcnt) res++;
            used[currow][curcol] = false;
            return;
        }
        if (currow > 0 && grid[currow - 1][curcol] != -1 && !used[currow - 1][curcol]) {
            search(grid, used, currow - 1, curcol, cnt + 1);
        }
        if (currow < rows - 1 && grid[currow + 1][curcol] != -1 && !used[currow + 1][curcol]) {
            search(grid, used, currow + 1, curcol, cnt + 1);
        }
        if (curcol > 0 && grid[currow][curcol - 1] != -1 && !used[currow][curcol - 1]) {
            search(grid, used, currow, curcol - 1, cnt + 1);
        }
        if (curcol < cols - 1 && grid[currow][curcol + 1] != -1 && !used[currow][curcol + 1]) {
            search(grid, used, currow, curcol + 1, cnt + 1);
        }
        used[currow][curcol] = false;
    }

private:
    int strow, stcol, endrow, endcol;
    int pathcnt;
    int rows, cols;
    int res;
};
