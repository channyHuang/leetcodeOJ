class Solution {
public:
    int findRotateSteps(string ring, string key) {
        rlen = ring.length();
        klen = key.length();
        map<char, vector<int>> maps;
        vector<vector<long long>> dp(rlen, vector<long long>(klen + 1, INT_MAX));
        long long res = INT_MAX;
        for (int i = 0; i < rlen; i++) {
            maps[ring[i]].push_back(i);
            dp[i][0] = min(i, rlen - i);
        }

        for (int j = 1; j <= klen; j++) {
            for (int x = 0; x < maps[key[j - 1]].size(); x++) {
                for (int i = 0; i < rlen; i++) {
                    dp[maps[key[j - 1]][x]][j] = min(dp[maps[key[j - 1]][x]][j], dp[i][j - 1] + dis(i, maps[key[j - 1]][x]) + 1);
                }
            }
        }
        //output(dp);
        for (int i = 0; i < rlen; i++) {
            res = min(res, dp[i][klen]);
        }
        return res;
    }

    int dis(long long a, long long b) {
        long long res = abs(a - b);
        return min(res, rlen - res);
    }

    void output(vector<vector<long long>> dp) {
        int rows = dp.size();
        int cols = dp[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << "----" << endl;
    }
private:
    int rlen, klen;
};
