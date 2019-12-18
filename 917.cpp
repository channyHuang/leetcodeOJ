class Solution {
public:
    string reverseOnlyLetters(string S) {
        int len = S.length();
        string res = S;
        int stPos = 0, endPos = len - 1;
        while (stPos < endPos) {
            while(stPos < endPos && !isCar(res[stPos])) stPos++;
            while (stPos < endPos && !isCar(res[endPos])) endPos--;
            if (stPos >= endPos) return res;
            char tmp = res[stPos];
            res[stPos] = res[endPos];
            res[endPos] = tmp;
            stPos++;
            endPos--;
        }
        return res;
    }

    bool isCar(char c) {
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= 'a' && c <= 'z') return true;
        return false;
    }
};
