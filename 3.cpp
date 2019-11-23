class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();

        if (len <= 0) return 0;
        if (len == 1) return 1;

        int maxLen = 1, curLen = 1;
        int appear[256] = {0};
        int stPos = 0;
        appear[(unsigned char)s[0]] = 1;
        for (int i = 1; i < len; i++) {
            if (appear[(unsigned char)s[i]] == 0) {
                curLen++;
            } else {
                if (maxLen < curLen) maxLen = curLen;
                curLen = i - appear[(unsigned char)s[i]] + 1;
                for (int j = stPos; j < appear[(unsigned char)s[i]] - 1; j++) {
                    appear[(unsigned char)s[j]] = 0;
                }
                stPos = appear[(unsigned char)s[i]];
            }
            appear[(unsigned char)s[i]] = i + 1;
        }
        if (maxLen < curLen) maxLen = curLen;
        return maxLen;
    }
};
