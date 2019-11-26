class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        int stPos = 0, i = 0;
        int len = text.length(), lenFirst = first.length(), lenSecond = second.length();
        int curStep = 1;
        while (stPos < len && text[stPos] == ' ') stPos++;
        while (len > stPos && text[len - 1] == ' ') len--;
        while (stPos < len) {
            if (curStep == 1) {
                if (stPos + lenFirst >= len) return res;
                if (text[stPos + lenFirst] != ' ') {
                    stPos = nextStPos(text, stPos, len);
                    continue;
                }
                for (i = 0; i < lenFirst; i++) {
                    if (text[stPos] != first[i]) break;
                    stPos++;
                }
                if (i == lenFirst) curStep = 2;
                stPos = nextStPos(text, stPos, len);
            } else if (curStep == 2) {
                if (stPos + lenSecond >= len) return res;
                if (text[stPos + lenSecond] != ' ') {
                    //stPos = nextStPos(text, stPos, len);
                    curStep = 1;
                    continue;
                }
                int beginPos = stPos;
                for (i = 0; i < lenSecond; i++) {
                    if (text[beginPos] != second[i]) break;
                    beginPos++;
                }
                if (i == lenSecond) {
                    curStep = 3;
                    stPos = nextStPos(text, stPos, len);
                }
                else curStep = 1;
            } else {
                curStep = 1;
                int nextPos = nextStPos(text, stPos, len);
                if (nextPos == len) res.push_back(text.substr(stPos, nextPos - stPos));
                else res.push_back(text.substr(stPos, nextPos - stPos - 1));
            }
        }
        return res;
    }

    int nextStPos(string text, int stPos, int len) {
        int res = stPos;
        while (res < len && text[res] != ' ') res++;
        if (res >= len) return res;
        res++;
        return res;
    }
};
