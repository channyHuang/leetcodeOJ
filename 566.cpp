class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> res;
        int rows = nums.size();
        if (rows <= 0) return nums;
        int cols = nums[0].size();
        if (cols <= 0) return nums;
        if (rows * cols != r * c) return nums;

        res.resize(r);
        for (int i = 0; i < r; i++) res[i].resize(c);
        int x = 0, y = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[x][y] = nums[i][j];
                y++;
                if (y >= c) {
                    y = 0;
                    x++;
                }
            }
        }
        return res;
    }
};
