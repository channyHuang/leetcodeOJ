class Solution {
public:
    int minFlips(string target) {
        int state = 0;
        int len = target.length();
        int res = 0;
        for (int pos = 0; pos < len; pos++) {
            if (target[pos] - '0' == state) continue;
            state = 1 - state;
            res++;
        }
        return res;
    }
};
