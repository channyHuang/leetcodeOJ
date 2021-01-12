class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();
        if (d > len) return -1;
        if (d == len) return accumulate(jobDifficulty.begin(), jobDifficulty.end(), 0);
        if (d == 1) return *max_element(jobDifficulty.begin(), jobDifficulty.end());
        vector<vector<int>> dp(len, vector<int>(d + 1, INT_MAX));
        //dp[i][j] job[i~len] using j days
        dp[len - 1][1] = jobDifficulty[len - 1];
        for (int i = len - 2; i >= d - 1; i--) {
            dp[i][1] = max(jobDifficulty[i], dp[i + 1][1]);
        }
        for (int j = 2; j <= d; j++) {
            for (int i = len - j; i >= d - j; i--) {
                int premax = 0;
                for (int x = i + 1; x <= len - j + 1; x++) {
                    //cout << j << " " << i << " " << x << endl;
                    premax = max(premax, jobDifficulty[x - 1]);
                    dp[i][j] = min(dp[i][j], dp[x][j - 1] + premax);
                }
            }
        }
        
        return dp[0][d];
    }
};
