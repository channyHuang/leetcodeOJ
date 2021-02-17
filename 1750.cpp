class Solution {
public:
    int minimumLength(string s) {
        int len = s.length();
        if (len <= 1) return len;
        int stPos = 0, endPos = len - 1;
        while (stPos < endPos && s[stPos] == s[endPos]) {
            char target = s[stPos++];
            while (stPos < endPos && s[stPos] == target) stPos++;
            endPos--;
            while (stPos < endPos && s[endPos] == target) endPos--; 
        }
        return endPos - stPos + 1;
    }
};
