class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int rows = matrix.size();
        if (rows <= 0) return res;
        int cols = matrix[0].size();
        if (cols <= 0) return res;

        vector<vector<bool>> used;
        for (int i = 0; i < rows + 2; i++) {
            vector<bool> subused;
            subused.resize(cols + 2);
            used.push_back(subused);
        }
        for (int i = 0; i < rows + 2; i++) {
            used[i][0] = true;
            used[i][cols + 1] = true;
        }
        for (int j = 0; j < cols + 2; j++) {
            used[0][j] = true;
            used[rows + 1][j] = true;
        }
        
        int dir = 0; //right, down, left, up
        int x[4] = {0, 1, 0, -1};
        int y[4] = {1, 0, -1, 0};
        int curRow = 1, curCol = 1;
        while (res.size() < rows * cols) {
            res.push_back(matrix[curRow - 1][curCol - 1]);
            used[curRow][curCol] = true;
            int nextRow = curRow + x[dir];
            int nextCol = curCol + y[dir];
            if (used[nextRow][nextCol]) dir = (dir + 1) % 4;
            curRow = curRow + x[dir];
            curCol = curCol + y[dir];
        }
        return res;
    }
};
