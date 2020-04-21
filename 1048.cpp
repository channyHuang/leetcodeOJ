class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int len = words.size();
        int res = 1;
        sort(words.begin(), words.end(), cmp);
        int dp[len];
        int used[len][26];
        memset(dp, 0, sizeof(dp));
        memset(used, 0, sizeof(used));
        dp[0] = 1;
        for (int i = 0; i < words[0].length(); i++) {
            used[0][words[0][i] - 'a']++;
        }
        for (int i = 1; i < len; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (words[i].length() > words[j].length() + 1) break;
                if (words[i].length() == words[j].length() + 1) {
                    int posi = 0, x;
                    for (x = 0; x < words[j].length(); x++) {
                        while (posi < words[i].length() && words[i][posi] != words[j][x]) posi++;
                        if (posi >= words[i].length()) break;
                        posi++;
                    }
                    if (x >= words[j].length()) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                } else continue;
            }
            res = max(res, dp[i]);
        }
        return res;
    }

    static bool cmp(string& a, string& b) {
        if (a.length() == b.length()) return a < b;
        return a.length() < b.length();
    }
};
