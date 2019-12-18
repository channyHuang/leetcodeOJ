class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.length();
        int half = len / 2;
        int i = 0;
        while ( i < half && s[i] == s[len - i - 1]) i++;
        if (i == half) return true;
        int pos = i;
        i++;
        while (i <= half && s[i] == s[len - i]) i++;
        if (i > half) return true;

        i = pos;
        while (i <= half && s[i] == s[len - i - 2]) i++;
        if (i > half) return true;
        return false;
    }
};
