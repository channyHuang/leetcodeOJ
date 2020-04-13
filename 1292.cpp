class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();
        int res = 0;
        int next = 1;

        for (int i = 0; i < rows; i++) {
            if (i + next > rows) break;
            for (int j = 0; j < cols; j++) {
                if (j + next > cols) break;
                int sum = 0;
                for (int x = i; x < i + next; x++) {
                    for (int y = j; y < j + next; y++) {
                        sum += mat[x][y];
                        if (sum > threshold) break;
                    }
                    if (sum > threshold) break;
                }
                if (sum <= threshold) {
                    res = next;
                    next++;
                    j--;
                }
            }
        }
        return res;
    }
};
