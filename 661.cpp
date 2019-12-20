class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res;
        int rows = M.size();
        if (rows <= 0) return res;
        int cols = M[0].size();
        if (cols <= 0) return res;
        for (int i = 0; i < rows; i++) {
            vector<int> sub;     
            for (int j = 0; j < cols; j++) {
                int sum = M[i][j];
                int count = 1;
                if (i - 1 >= 0) {
                    sum += M[i - 1][j];
                    count++;
                    if (j - 1 >= 0) {
                        sum += M[i - 1][j - 1];
                        count++;
                    }
                    if (j + 1 < cols) {
                        sum += M[i - 1][j + 1];
                        count++;
                    }
                }
                if (i + 1 < rows) {
                    sum += M[i + 1][j];
                    count++;
                    if (j - 1 >= 0) {
                        sum += M[i + 1][j - 1];
                        count++;
                    }
                    if (j + 1 < cols) {
                        sum += M[i + 1][j + 1];
                        count++;
                    }
                } 
                if (j - 1 >= 0) {
                    sum += M[i][j - 1];
                    count++;
                }
                if (j + 1 < cols) {
                    sum += M[i][j + 1];
                    count++;
                }
                sum /= count;
                sub.push_back(sum);
            }
            res.push_back(sub);
        }
        return res;
    }
};
