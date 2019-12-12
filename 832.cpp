class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rows = A.size();
        vector<vector<int>> res;
        if (rows <= 0) return res;
        int cols = A[0].size();
        if (cols <= 0) return res;
        for (int i = 0; i < rows; i++) {
            vector<int> subres;
            for (int j = cols - 1; j >= 0; j--) {
                if (A[i][j] == 0) subres.push_back(1);
                else subres.push_back(0);
            }
            res.push_back(subres);
        }
        return res;
    }
};
