class Solution {
public:
    int titleToNumber(string s) {
        int len = 0;
        int res = 0;
        while (s[len] != '\0') {
            res = res * 26 + (s[len] - 'A' + 1);
            len++;
        }
        return res;
    }
};
