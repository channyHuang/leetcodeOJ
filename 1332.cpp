class Solution {
public:
    int removePalindromeSub(string s) {
        int len = s.length();
        if (len == 0) return 0;
        bool flag = true;
        int mid = len / 2;
        if (len & 1) {
            for (int i = 1; i <= mid; i++) {
                if (s[mid + i] != s[mid - i]) {
                    flag = false;
                    break;
                }
            }
        } else {
            for (int i = 1; i <= mid; i++) {
                if (s[mid + i - 1] != s[mid - i]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) return 1;
        return 2;
    }
};