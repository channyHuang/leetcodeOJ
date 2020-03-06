class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int rows = A.size();
        if (rows <= 0) return 0;
        int cols = A[0].size();
        if (cols <= 0) return 0;
        int base = (1 << cols);
        int res = 0;
        int count[cols] = {0};
        for (int i = 0; i < rows; i++) {
            res += (1 << (cols - 1));
            if (A[i][0] == 1) {   
                for (int j = 1; j < cols; j++) {
                    res += (A[i][j] << (cols - j - 1));
                    count[j] += A[i][j];
                }
            } else {
                A[i][0] = 1;
                for (int j = 1; j < cols; j++) {
                    A[i][j] = 1 - A[i][j]; 
                    res += (A[i][j] << (cols - j - 1));
                    count[j] += A[i][j];
                }
            }
        }
    
        for (int j = 1; j < cols; j++) {
            if (count[j] < (rows >> 1) + (rows & 1)) {
                int tmp = rows - (count[j] << 1);
                res += ((1 << (cols - j - 1)) * tmp);
            }
        }
        
        return res;
    }
};
