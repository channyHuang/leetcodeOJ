class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int rows = accounts.size();
        if (rows <= 0) return 0;
        int cols = accounts[0].size();
        if (cols <= 0) return 0;
        int maxn = 0;
        for (int i = 0; i < rows; i++) {
            int sum = 0;
            for (int j = 0; j < cols; j++) {
                sum += accounts[i][j];
            }
            if (maxn < sum) {
                maxn = sum;
            }
        }
        return maxn;
    }
};
