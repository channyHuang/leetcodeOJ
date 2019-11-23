class Solution {
public:
    string reverseWords(string s) {
        string res;
        int stPos = 0, endPos = 0;
        int len = s.length();
        while (stPos < len) {
            while (endPos < len && s[endPos] != ' ') endPos++;
            endPos--;
            if (res.length() != 0) res += " ";
            res += reverse(s, stPos, endPos);
            stPos = endPos + 2;
            endPos = stPos;
        }
        return res;
    }

    string reverse(string s, int stPos, int endPos) {
        int len = endPos - stPos + 1;
        string res = s.substr(stPos, len);
        int mid = len / 2;
        if (len % 2 == 0) mid--;
        for (int i = 0; i <= mid; i++) {
            char tmp = res[i];
            res[i] = res[len - i - 1];
            res[len - i - 1] = tmp;
        }
        return res;
    }
};
