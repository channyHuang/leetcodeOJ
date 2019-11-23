class Solution {
public:
    string reverseStr(string s, int k) {
        string res;
        int len = s.length();
        if (k <= 1) {
            res = s;
            return res;
        }
        for (int i = 0; i < len; i += k + k) {
            if (i + k - 1 < len) {
                res += reverse(s, i, i + k - 1);
            } else {
                res += reverse(s, i, len - 1);
            }
            if (i + k < len) res += s.substr(i + k, k);
        }
        return res;
    }

    string reverse(string s, int stPos, int endPos) {
        int len = endPos - stPos + 1;
        string res = s.substr(stPos, len);
        int mid = len / 2 + len % 2;
        for (int i = 0; i < mid; i++) {
            char tmp = res[i];
            res[i] = res[len - i - 1];
            res[len - i - 1] = tmp;
        }
        return res;
    }
};
