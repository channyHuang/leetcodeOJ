class Solution {
public:
    int numSteps(string s) {
        int len = s.length();
        int pos = len - 1;
        int res = 0;

        while (pos > 0) {
            while (pos > 0 && s[pos] == '0') {
                res++;
                pos--;
            }
            if (pos == 0) break;
            res++;
            while (pos > 0 && s[pos] == '1') {
                res++;
                pos--;
            }
            if (pos == 0) {
                res++;
                break;
            } else {
                s[pos] = '1';
            }
        }
        return res;
    }
};
