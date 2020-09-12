class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rows = mat.size();
        int res = 0;
        for (int i = 0; i < rows; i++) {
            res += mat[i][i];
            if (i != rows - i - 1) 
                res += mat[i][rows - i - 1];
        }
        return res;
    }
};
