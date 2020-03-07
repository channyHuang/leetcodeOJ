class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        bool valid[len][len] = {0};
        int count[len][len] = {0};
        for (int i = 0; i < len; i++) {
            valid[i][i] = true;
            count[i][i] = 1;
            if (i + 1 < len) {
                valid[i][i + 1] = (s[i] == s[i + 1] ? true : false);
                count[i][i + 1] = (s[i] == s[i + 1] ? 3 : 2);
            }
        }
        for (int l = 2; l < len; l++) {
            for (int i = 0; i + l < len; i++) {
                valid[i][i + l] = ((s[i] == s[i + l] && valid[i + 1][i + l - 1]) ? true : false);
                count[i][i + l] = count[i][i + l - 1] + 1;
                if (s[i + l] == s[i + l - 1]) count[i][i + l]++;
                for (int k = i; k < i + l - 1; k++) {
                    if (s[k] == s[i + l] && valid[k + 1][i + l - 1]) count[i][i + l]++;
                }
            }
        }
        return count[0][len - 1];
    }
};
