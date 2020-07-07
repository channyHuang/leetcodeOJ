class Solution {
public:
    bool isNumber(string s) {
        int len = s.length();
        int stPos = 0;
        while (stPos < len && s[stPos] == ' ') stPos++;
        if (stPos >= len) return false;
        int endPos = len - 1;
        while (endPos >= stPos && s[endPos] == ' ') endPos--;

        string mid = s.substr(stPos, endPos - stPos + 1);
        return (isInt(mid) || isFloat(mid) || isENum(mid));
    }

    bool isInt(string str, bool bContainSimbol = false) {
        if (str.empty()) return false;
        int i = 0;
        if (bContainSimbol) {
            if (str[0] == '+' || str[0] == '-') i = 1;
        }
        for (; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9') continue;
            return false;
        }
        return true;
    }

    bool isFloat(string str, bool bContainSimbol = true) {
        if (str.empty()) return false;
        if (isInt(str, bContainSimbol)) return true;
        int idx = str.find_first_of(".", 0);
        if (idx < 0) return false;
        return isInt(str.substr(0, idx), bContainSimbol) && isInt(str.substr(idx + 1));
    }

    bool isENum(string str) {
        int idx = str.find_first_of("e", 0);
        if (idx < 0) return false;
        return isFloat(str.substr(0, idx), true) && isInt(str.substr(idx + 1), true);
    }
};
