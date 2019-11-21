class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() <= 1) return true;
        int stPos = 0, endPos = s.length() - 1;
        while (1) {
            while (stPos < endPos && !valid(s[stPos])) stPos++;
            while (endPos > stPos && !valid(s[endPos])) endPos--;
            if (stPos >= endPos) return true;
            if (same(s[stPos], s[endPos])) {
                stPos++;
                endPos--;
            } else return false;
        }
        return true;
    }

    bool valid(char c) {
        if (c >= '0' && c <= '9') return true;
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        return false;
    }

    bool same(char a, char b) {
        if (a == b) return true;
        if (a >= 'a' && a <= 'z' && b >= 'A' && b <= 'Z') {
            if (a - 'a' == b - 'A') return true;
            return false;
        } 
        if (a >= 'A' && a <= 'Z' && b >= 'a' && b <= 'z') {
            if (a - 'A' == b - 'a') return true;
            return false;
        }
        return false;
    }
};
