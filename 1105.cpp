class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int len = books.size();
        if (len == 1) return books[0][1];
        int dp[len];
        memset(dp, 0, sizeof(dp));
        dp[0] = books[0][1];
        for (int i = 1; i < len; i++) {
            dp[i] = dp[i - 1] + books[i][1];
            int curWidth = books[i][0];
            int curHeight = books[i][1];
            for (int j = i - 1; j >= 0; j--) {
                curWidth += books[j][0];
                curHeight = max(curHeight, books[j][1]);
                if (curWidth > shelf_width) break;
                if (j == 0) dp[i] = min(dp[i], curHeight);
                else dp[i] = min(dp[i], dp[j - 1] + curHeight);
            }
        }
        return dp[len - 1];
    }
};
