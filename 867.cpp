class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        vector<vector<int>> res;
        res.resize(cols);
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                res[i].push_back(A[j][i]);
            }
        }
        return res;
    }
};
