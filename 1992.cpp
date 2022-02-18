class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        row = land.size();
        if (row == 0) return res;
        col = land[0].size();
        vector<vector<bool>> used(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (used[i][j] || land[i][j] == 0) continue;
                int maxr = i;
                int maxc = j;
                search(i, j, land, used, maxr, maxc);
                vector<int> sub = {i, j, maxr, maxc};
                res.push_back(sub);
            }
        }
        return res;
    }

    void search(int r, int c, vector<vector<int>>& land, vector<vector<bool>>& used, int &maxr, int &maxc) {
        used[r][c] = true;
        maxr = std::max(maxr, r);
        maxc = std::max(maxc, c);
        if (r > 0 && !used[r - 1][c] && land[r - 1][c] == 1) search(r - 1, c, land, used, maxr, maxc);
        if ((r < row - 1) && !used[r + 1][c] && land[r + 1][c] == 1) search(r + 1, c, land, used, maxr, maxc);
        if (c > 0 && !used[r][c - 1] && land[r][c - 1] == 1) search(r, c - 1, land, used, maxr, maxc);
        if (c < col - 1 && !used[r][c + 1] && land[r][c + 1] == 1) search(r, c + 1, land, used, maxr, maxc);
    }

private:
    int row = 0;
    int col = 0;
    vector<vector<int>> res;
};
