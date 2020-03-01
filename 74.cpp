class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows <= 0) return 0;
        int cols = matrix[0].size();
        if (cols <= 0) return 0;
        int stPos = 0, endPos = rows * cols - 1;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            int r = midPos / cols;
            int c = midPos % cols;
            if (matrix[r][c] == target) return true;
            else if (matrix[r][c] < target) stPos = midPos + 1;
            else endPos = midPos - 1;
        }
        return false;
    }
};
