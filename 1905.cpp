class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        row = grid2.size();
        col = grid2[0].size();
        int res = 0;
        used.resize(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (used[i][j] || (grid2[i][j] == 0)) continue;
                bool re = search(i, j, grid1, grid2);
                if (re) res++;
            }
        }
        return res;
    }

    bool search(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        bool res = true;
        used[r][c] = true;
        if (grid1[r][c] == 0) res = false;
        if (r > 0 && !used[r - 1][c] && grid2[r - 1][c] == 1) {
            bool re = search(r - 1, c, grid1, grid2);
            res &= re;
        }
        if (r < row - 1 && !used[r + 1][c] && grid2[r + 1][c] == 1) {
            bool re = search(r + 1, c, grid1, grid2);
            res &= re;
        }
        if (c > 0 && !used[r][c - 1] && grid2[r][c - 1] == 1) {
            bool re = search(r, c - 1, grid1, grid2);
            res &= re;
        }
        if (c < col - 1 && !used[r][c + 1] && grid2[r][c + 1] == 1) {
            bool re = search(r, c + 1, grid1, grid2);
            res &= re;
        }
        return res;
    }

private:
    int row, col;
    vector<vector<bool>> used;
};