class Solution {
public:
    int countEval(string s, int result) {
        int len = s.length();
        vector<vector<int>> dp0(len, vector<int>(len, 0));
        vector<vector<int>> dp1(len, vector<int>(len, 0));
        for (int i = 0; i < len; i += 2) {
            if (s[i] == '0') dp0[i][i] =1;
            else dp1[i][i] = 1;
        }

        for (int l = 2; l < len; l += 2) {
            for (int i = 0; i < len; i += 2) {
                if (i + l >= len) break;
                for (int o = i + 1; o < i + l; o += 2) {
                    switch (s[o]) {
                    case '&':
                        dp0[i][i + l] += (dp0[i][o - 1] * dp0[o + 1][i + l] + dp1[i][o - 1] * dp0[o + 1][i + l] + dp0[i][o - 1] * dp1[o + 1][i + l]);
                        dp1[i][i + l] += (dp1[i][o - 1] * dp1[o + 1][i + l]);
                        break;
                    case '|':
                        dp1[i][i + l] += (dp1[i][o - 1] * dp0[o + 1][i + l] + dp0[i][o - 1] * dp1[o + 1][i + l] + dp1[i][o - 1] * dp1[o + 1][i + l]);
                        dp0[i][i + l] += (dp0[i][o - 1] * dp0[o + 1][i + l]);
                        break;
                    case '^':
                        dp1[i][i + l] += (dp1[i][o - 1] * dp0[o + 1][i + l] + dp0[i][o - 1] * dp1[o + 1][i + l]);
                        dp0[i][i + l] += (dp0[i][o - 1] * dp0[o + 1][i + l] + dp1[i][o - 1] * dp1[o + 1][i + l]);
                        break;
                    default:
                        break;
                    }
                    
                }
            }
        }
        return (result ? dp1[0][len - 1] : dp0[0][len - 1]);
    }
};
