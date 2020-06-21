class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) return false;
        bool res[len1 + 1][len2 + 1];
        memset(res, false, sizeof(res));
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                if (i == 0 && j == 0) res[i][j] = true;
                else if (i == 0) res[i][j] = ((s2[j - 1] == s3[j - 1]) && res[i][j - 1]);
                else if (j == 0) res[i][j] = ((s1[i - 1] == s3[i - 1]) && res[i - 1][j]);
                else {
                    res[i][j] = ((s1[i - 1] == s3[i + j - 1]) && res[i - 1][j]
                            || ((s2[j - 1] == s3[i + j - 1]) && res[i][j - 1]));
                }
            }
        }
/*
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                std::cout << res[i][j] << " ";
            }
            std::cout << std::endl;
        }
*/
        return res[len1][len2];
    }
};
