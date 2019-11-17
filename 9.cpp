class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        int len = 0;
        char chx[30] = {0};
        if (x < 0) chx[len++] = '-';
        while (x != 0) {
            chx[len++] = x % 10;
            x /= 10;
        }

        if (len == 0) return false;
        else if (len == 1) return true;

        int i = 0;
        while (i <= len / 2) {
            if (chx[i] != chx[len - i - 1]) return false;
            i++;
        }
        return true;

    }
};
