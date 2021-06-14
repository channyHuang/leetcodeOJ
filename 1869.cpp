class Solution {
public:
    bool checkZeroOnes(string s) {
        int len = s.length();
        char pre = s[0];
        int max1 = (s[0] == '1' ? 1 : 0), max0 = (s[0] == '0' ? 1 : 0);
        int lastlen = 1;
        for (int i = 1; i < len; i++) {
            if (s[i] == pre) {
                lastlen++;
                continue;
            }

            if (pre == '0') max0 = max(max0, lastlen);
            else max1 = max(max1, lastlen);
            lastlen = 1;
            pre = s[i];
        }

        if (pre == '0') max0 = max(max0, lastlen);
        else max1 = max(max1, lastlen);

        return (max1 > max0);
    }
};
