class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10) return N;
        string str = to_string(N);
        int len = str.length();
        int i;
        for (i = 0; i < len - 1; i++) {
            if (str[i + 1] < str[i]) break;
        }
        if (i >= len - 1) return N;
        str[i]--;
        while (i > 0 && str[i - 1] > str[i]) {
            i--;
            str[i]--;
        }
        int res = 0;
        for (int j = 0; j < len; j++) {
            if (j > i) res = res * 10 + 9;
            else res = res * 10 + str[j] - '0';
        }
        return res;
    }
};