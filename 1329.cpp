class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size();
        if (rows <= 0) return mat;
        int cols = mat[0].size();
        if (cols <= 0) return mat;

        for (int i = 0; i < rows; i++) {
            sort(mat, rows, cols, i, 0);
        }
        for (int i = 1; i < cols; i++) {
            sort(mat, rows, cols, 0, i);
        }
        return mat;
    }

    void sort(vector<vector<int>>& mat, int rows, int cols, int i, int j) {
        bool flag = false;
        while (i < rows && j < cols) {
            int x = i, y = j;
            while (x - 1 >= 0 && y - 1 >= 0) {
                if (mat[x - 1][y - 1] > mat[x][y]) {
                    int tmp = mat[x][y];
                    mat[x][y] = mat[x - 1][y - 1];
                    mat[x - 1][y - 1] = tmp;
                    x--;
                    y--;
                } else break;
            }
            i++;
            j++;
        }
    }
};
