class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        if (rows <= 0) return res;
        int cols = matrix[0].size();
        if (cols <= 0) return res;
        int dir = 0; //0 up 1 down
        int x[2] = {-1, 1};
        int y[2] = {1, -1};
        int curRow = 0;
        int curCol = 0;
        while (1) {
            res.push_back(matrix[curRow][curCol]);
            if (res.size() >= rows * cols) break;
            int nextRow = curRow + x[dir];
            int nextCol = curCol + y[dir];
            if (nextRow < 0) {
                dir = 1 - dir;
                if (nextCol >= cols) {
                    nextRow = curRow + 1;
                    nextCol = curCol;
                } else {
                    nextRow = curRow;
                }
            } else if (nextCol < 0) {
                dir = 1 - dir;
                if (nextRow >= rows) {
                    nextCol = curCol + 1;
                    nextRow = curRow;
                } else {
                    nextCol = curCol;
                }
            } else if (nextRow >= rows) {
                dir = 1 - dir;
                nextRow = curRow;
                nextCol = curCol + 1;
            } else if (nextCol >= cols) {
                dir = 1 - dir;
                nextRow = curRow + 1;
                nextCol = curCol;
            }
            curRow = nextRow;
            curCol = nextCol;
        }
        return res;
    }
};
