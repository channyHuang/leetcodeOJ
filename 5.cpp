class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int maxlen = 1;
        int maxcen = 0;
        for (int i = 1; i < len; i++) {
            int curlen = search(s, i - 1, i + 1, len);
            if (curlen > maxlen) {
                maxlen = curlen;
                maxcen = i;
            }

            curlen = search(s, i - 1, i, len);
            if (curlen > maxlen) {
                maxlen = curlen;
                maxcen = i;
            }
        }
        return s.substr(maxcen - maxlen / 2, maxlen);
    }

    int search(string s, int left, int right, int len) {
        while (left >= 0 && right < len) {
            if (s[left] != s[right]) break;
            left--;
            right++;
        }
        return right - left - 1;
    }
};
