class Solution {
public:
    int minimumDistance(string word) {
        int len = word.length();
        if (len <= 2) return 0;
        vector<vector<int>> dist(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            int ri = i / 6;
            int ci = i % 6;
            for (int j = i + 1; j < 26; j++) {
                int rj = j / 6;
                int cj = j % 6;

                dist[i][j] = abs(ri - rj) + abs(ci - cj);
                dist[j][i] = dist[i][j];
            }
        }
        /*
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }*/

        vector<int> target(len, 0);
        for (int j = 0; j < len; j++) {
            target[j] = word[j] - 'A';
        }
        vector<vector<int>> dp(len, vector<int>(len, INT_MAX));
        dp[0][1] = 0;
        int sum = 0;
        for (int j = 2; j < len; j++) {
            dp[0][j] = dp[0][j - 1] + dist[target[j - 1]][target[j]];
            sum += dist[target[j - 1]][target[j - 2]];
            dp[j - 1][j] = min(dp[j - 1][j], sum);
        }
        int res = dp[0][len - 1];
        for (int i = 1; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (j > i + 1) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + dist[target[j - 1]][target[j]]);
                } else {
                    for (int k = 0; k < i; k++) {
                        dp[i][j] = min(dp[i][j], dp[k][i] + dist[target[k]][target[j]]);
                    }
                }
            }

            res = min(res, dp[i][len - 1]);
        }  
        /*
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/ 

        return res;
    }
};
