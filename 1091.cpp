class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows <= 0) return -1;
        int cols = grid[0].size();
        if (cols <= 0) return -1;
        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1) return -1;
        res = rows * cols + 1;
        search(grid, rows, cols);
        if (res == rows * cols + 1) return -1;
        return res;
    }
    
    void search(vector<vector<int>>& grid, int rows, int cols) {
        int step[102][102];
        step[0][0] = 1;
        queue<pair<int, int>> qu;
        qu.push(pair<int, int>(0, 0));
        while (!qu.empty()) {
            pair<int, int> curPair = qu.front();
            qu.pop();
            int r = curPair.first;
            int c = curPair.second;
            if (r == rows - 1 && c == cols - 1) {
                res = step[r][c];
                return;
            }
            if (r > 0) {
                if (step[r - 1][c] == 0 && grid[r - 1][c] == 0) {
                    qu.push(pair<int, int>(r - 1, c));
                    step[r - 1][c] = step[r][c] + 1;
                }
                if (c > 0 && step[r - 1][c - 1] == 0 && grid[r - 1][c - 1] == 0) {
                    qu.push(pair<int, int>(r - 1, c - 1));
                    step[r - 1][c - 1] = step[r][c] + 1;
                }
                if (c < cols - 1 && step[r - 1][c + 1] == 0 && grid[r - 1][c + 1] == 0) {
                    qu.push(pair<int, int>(r - 1, c + 1));
                    step[r - 1][c + 1] = step[r][c] + 1;
                }
            }
            if (r < rows - 1) {
                if (step[r + 1][c] == 0 && grid[r + 1][c] == 0) {
                    qu.push(pair<int, int>(r + 1, c));
                    step[r + 1][c] = step[r][c] + 1;
                }
                if (c > 0 && step[r + 1][c - 1] == 0 && grid[r + 1][c - 1] == 0)  {
                    qu.push(pair<int, int>(r + 1, c - 1));
                    step[r + 1][c - 1] = step[r][c] + 1;
                }
                if (c < cols - 1 && step[r + 1][c + 1] == 0 && grid[r + 1][c + 1] == 0)  {
                    qu.push(pair<int, int>(r + 1, c + 1));
                    step[r + 1][c + 1] = step[r][c] + 1;
                }
            }
            if (c > 0 && step[r][c - 1] == 0 && grid[r][c - 1] == 0) {
                qu.push(pair<int, int>(r, c - 1));
                step[r][c - 1] = step[r][c] + 1;
            }
            if (c < cols - 1 && step[r][c + 1] == 0 && grid[r][c + 1] == 0) {
                qu.push(pair<int, int>(r, c + 1));
                step[r][c + 1] = step[r][c] + 1;
            }
        }
    }

private:
    int res;
};
