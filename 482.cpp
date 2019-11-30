class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = S + S;
        int posR = 0, posS = 0;
        int len = S.length();
        while (posS < len && S[posS] == '-') posS++;
        if (posS >= len) return "";

        while (posS < len && S[posS] != '-') res[posR++] = toLarger(S[posS++]);
        if (posS >= len) {
            res[posR] = 0;
            return res;
        }
        while (posS < len && S[posS] == '-') posS++;
        if (posS >= len) {
            res[posR] = 0;
            return res;
        }
        res[posR++] = '-';
        int curLen = 0;
        while(posS < len) {
            while (posS < len && S[posS] == '-') posS++;
            if (posS >= len) {
                res[posR] = 0;
                return res;
            }
            if (curLen >= K) {
                res[posR++] = '-';
                curLen = 0;
            }
            res[posR++] = toLarger(S[posS++]);
            curLen++;
        }
        res[posR] = 0;
        return res;
    }

    char toLarger(char c) {
        if (c >= 'a' && c <= 'z') return c + 'A' - 'a';
        return c;
    }
};
