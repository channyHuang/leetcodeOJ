class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        int len = s.length();
        while (s[len - 1] == ' ') len--;
        for (i = len - 1; i >= 0; i--) {
            if (s[i] == ' ') break;
        }
        if (i >= 0) return len - i - 1;
        else return len;
    }
};
