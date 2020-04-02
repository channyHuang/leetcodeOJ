class Solution {
public:
    string pushDominoes(string dominoes) {
        string res = dominoes;
        int len = dominoes.length();
        if (len <= 1) return res;
        string::size_type pos = dominoes.find_first_of("LR", 0);
        int stPos = dominoes.find_first_not_of("LR", 0);
        while (pos != string::npos) {
            if (stPos == string::npos) break;
            if (dominoes[pos] == 'L') {
                int endPos = pos - 1;
                while (stPos <= endPos) {
                    res[stPos] = 'L';
                    res[endPos] = 'L';
                    stPos++;
                    endPos--;
                }
                stPos = dominoes.find_first_not_of("LR", pos);
            } else {
                stPos = dominoes.find_first_not_of("LR", pos);
                string::size_type nextPos = dominoes.find_first_of("LR", pos + 1);
                if (nextPos == string::npos) {
                    if (stPos == string::npos) break;
                    int endPos = dominoes.find_last_of(".");
                    while (stPos <= endPos) {
                        res[stPos++] = 'R';
                        res[endPos--] = 'R';
                    }
                    break;
                }
                else if (dominoes[nextPos] == 'L') {
                    int endPos = nextPos - 1;
                    while (stPos < endPos) {
                        res[stPos] = 'R';
                        res[endPos] = 'L';
                        stPos++;
                        endPos--;
                    }
                    stPos = dominoes.find_first_not_of("LR", nextPos + 1);
                } else {
                    stPos = dominoes.find_first_not_of("LR", pos);
                    if (stPos == string::npos) break;
                    int endPos = nextPos - 1;
                    while (stPos <= endPos) {
                        res[stPos] = 'R';
                        res[endPos] = 'R';
                        stPos++;
                        endPos--;
                    }
                    stPos = dominoes.find_first_not_of("LR", nextPos + 1);
                    pos = nextPos;
                    continue;
                }
            }
            pos = dominoes.find_first_of("LR", pos + 1);
        }
        return res;
    }
};
