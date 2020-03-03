class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows <= 0) return false;
        int cols = matrix[0].size();
        if (cols <= 0) return false;

        if (matrix[0][0] > target || matrix[rows - 1][cols - 1] < target) return false;
        return find(matrix, target, 0, 0, rows - 1, cols - 1);
    }

    bool find(vector<vector<int>>& matrix, int target, int stRow, int stCol, int endRow, int endCol) {
        if (stRow > endRow || stCol > endCol) return false;
        if (stRow == endRow && stCol == endCol) return matrix[stRow][stCol] == target;
        bool flag = false;
         {
            int midRow = (stRow + endRow) / 2;
            int midCol = (stCol + endCol) / 2;
            if (matrix[midRow][midCol] == target) return true;
            if (matrix[midRow][midCol] > target) {
                flag = find(matrix, target, stRow, stCol, midRow, midCol);
                if (!flag) flag = find(matrix, target, midRow + 1, stCol, endRow, midCol - 1);
                if (!flag) flag = find(matrix, target, stRow, midCol + 1, midRow - 1, endCol);
            }
            else {
                flag = find(matrix, target, midRow + 1, stCol, endRow, midCol);
                if (!flag) flag = find(matrix, target, stRow, midCol + 1, midRow, endCol);
                if (!flag) flag = find(matrix, target, midRow + 1, midCol + 1, endRow, endCol);
            }
        }
        return flag;
    }
};
