class Solution {
public:
    class Node {
    public:
        int minn[2];
        vector<int> minidx[2];
    };

    class SearchNode {
    public:
        int curRow;
        int curRes;
        int lastCol;
        SearchNode(int _row = 0, int _res = 0, int _col = 0) {
            curRow = _row;
            curRes = _res;
            lastCol = _col;
        }
    };

    int minFallingPathSum(vector<vector<int>>& arr) {
        len = arr.size();
        if (len == 1) return arr[0][0];
        if (len == 2) return min(arr[0][0] + arr[1][1], arr[0][1] + arr[1][0]);
        dp.resize(len, vector<int>(len, 0));
        int minidx = (arr[0][0] < arr[0][1] ? 0 : 1);
        int minsecond = (arr[0][0] < arr[0][1] ? 1 : 0);
        for (int i = 0; i < len; i++) {
            dp[0][i] = arr[0][i];
            if (i < 2) continue;
            if (dp[0][i] <= dp[0][minidx]) {
                minsecond = minidx;
                minidx = i;
            } else if (dp[0][i] < dp[0][minsecond]) {
                minsecond = i;
            }
        }
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < len; j++) {
                dp[i][j] = (minidx == j ? dp[i - 1][minsecond] + arr[i][j] : dp[i - 1][minidx] + arr[i][j]);
            }
            minidx = (dp[i][0] < dp[i][1] ? 0 : 1);
            minsecond = (dp[i][0] < dp[i][1] ? 1 : 0);
            for (int j = 2; j < len; j++) {
                if (dp[i][j] <= dp[i][minidx]) {
                    minsecond = minidx;
                    minidx = j;
                } else if (dp[i][j] < dp[i][minsecond]) {
                    minsecond = j;
                }
            }
        }
        res = dp[len - 1][0];
        for (int j = 1; j < len; j++) {
            res = min(res, dp[len - 1][j]);
        }
        return res;
    }

private:
    int len;
    vector<vector<int>> dp;
    int res;
};
