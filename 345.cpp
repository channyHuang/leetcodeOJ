class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        string res = s;
        int stPos = 0, endPos = len - 1;
        while (stPos < endPos) {
            while (stPos < endPos && !isTarget(s[stPos])) stPos++;
            while (stPos < endPos && !isTarget(s[endPos])) endPos--;
            if (stPos >= endPos) return res;
            res[stPos] = s[endPos];
            res[endPos] = s[stPos];
            stPos++;
            endPos--;
        }
        return res;
    }

    bool isTarget(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return true;
        return false; 
    }
};
