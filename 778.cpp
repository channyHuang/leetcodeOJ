class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> minSteps(rows, vector<int>(cols, INT_MAX)); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> qu;
        int res = INT_MAX;
        qu.push(pair<int, int>(grid[0][0], 0));
        while (!qu.empty()) {
            pair<int, int> cur = qu.top();
            qu.pop();
            int row, col;
            decodeIndex(cur.second, row, col);

            if (row == rows - 1 && col == cols - 1) {
                res = cur.first;
                break;
            }

            if (row + 1 < rows) {
                int step = max(grid[row + 1][col], cur.first);
                if (minSteps[row + 1][col] > step) {
                    minSteps[row + 1][col] = step;
                    qu.push(pair<int, int>(step, encodeIndex(row + 1, col)));
                }
            }
            if (row - 1 >= 0) {
                int step = max(grid[row - 1][col], cur.first);
                if (minSteps[row - 1][col] > step) {
                    minSteps[row - 1][col] = step;
                    qu.push(pair<int, int>(step, encodeIndex(row - 1, col)));
                }
            }
            if (col + 1 < cols) {
                int step = max(grid[row][col + 1], cur.first);
                if (minSteps[row][col + 1] > step) {
                    minSteps[row][col + 1] = step;
                    qu.push(pair<int, int>(step, encodeIndex(row, col + 1)));
                }
            }
            if (col - 1 >= 0) {
                int step = max(grid[row][col - 1], cur.first);
                if (minSteps[row][col - 1] > step) {
                    minSteps[row][col - 1] = step;
                    qu.push(pair<int, int>(step, encodeIndex(row, col - 1)));
                }
            }
        }
        return res;
    }

    void decodeIndex(int index, int& row, int& col) {
        row = index / cols;
        col = index % cols;
    }

    int encodeIndex(int row, int col) {
        return row * cols + col;
    }

private:
    int rows;
    int cols;
};
