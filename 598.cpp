class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int rows = ops.size();
        //if (rows <= 0) return 0;
        int minRow = m, minCol = n;
        for (int i = 0; i < rows; i++) {
            if (minRow > ops[i][0]) minRow = ops[i][0];
            if (minCol > ops[i][1]) minCol = ops[i][1];
        }
        return minRow * minCol;
    }
};
