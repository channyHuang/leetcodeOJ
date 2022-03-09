class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row <= 0) return false;
        int col = matrix[0].size();
        if (col <= 0) return false;
        return searchsub(matrix, target, 0, 0, row - 1, col - 1);
    }

    bool searchsub(vector<vector<int>>& matrix, int target, int strow, int stcol, int endrow, int endcol) {
        if (strow > endrow || stcol > endcol) return false;
        if (strow == endrow && stcol == endcol) return (matrix[strow][stcol] == target);
        int midrow = (strow + endrow) / 2;
        int midcol = (stcol + endcol) / 2;
        if (matrix[midrow][midcol] == target) return true;
        if (matrix[midrow][midcol] > target) {
            if (searchsub(matrix, target, strow, stcol, midrow, midcol)) return true;
            if (searchsub(matrix, target, strow, midcol + 1, midrow - 1, endcol)) return true;
            if (searchsub(matrix, target, midrow, stcol, endrow, midcol - 1)) return true;
            return false;
        }
        if (searchsub(matrix, target, strow, midcol + 1, midrow, endcol)) return true;
        if (searchsub(matrix, target, midrow + 1, stcol, endrow, midcol)) return true;
        if (searchsub(matrix, target, midrow + 1, midcol + 1, endrow, endcol)) return true;
        return false;
    }
};
