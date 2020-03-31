class Solution {
public:
    string decodeString(string s) {
        while (1) {
            string::size_type endPos = s.find_first_of("]", 0);
            if (endPos == string::npos) return s;
            string::size_type stPos = s.substr(0, endPos).find_last_of("[");
            int numPos = stPos - 1;
            int repeat = 0;
            int base = 1;
            while (numPos >= 0 && s[numPos] >= '0' && s[numPos] <= '9') {
                repeat = repeat + (s[numPos] - '0') * base;
                base *= 10;
                numPos--;
            }
            string repStr = s.substr(stPos + 1, endPos - stPos - 1);
            string replaceStr = repStr;
            for (int i = 1; i < repeat; i++) {
                replaceStr += repStr;
            }
            s.replace(numPos + 1, endPos - numPos, replaceStr);
        }
        return s;
    }
};
