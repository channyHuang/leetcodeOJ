class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenh = haystack.length(), lenn = needle.length();
        if (lenn <= 0) return 0;
        if (lenh <= 0) return -1;
        for (int i = 0; i <= lenh - lenn; i++) {
            int j;
            for (j = 0; j < lenn; j++) {
                if (needle[j] != haystack[i + j]) break;
            }
            if (j >= lenn) return i;
        }
        return -1;
    }
};
