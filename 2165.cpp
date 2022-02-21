class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        bool positive = true;
        if (num < 0) {
            positive = false;
            num = -num;
        }
        string str = to_string(num);
        sort(str.begin(), str.end());
        int len = str.length();
        long long res = 0;
        if (positive) {
            int pos = 0;
            while (str[pos] == '0') pos++;
            if (pos > 0) {
                str[0] = str[pos];
                str[pos] = '0';
            }
            for (int i = 0; i < len; ++i) {
                res = res * 10 + (str[i] - '0');
            }
        } else {
            for (int i = len - 1; i >= 0; i--) {
                res = res * 10 + (str[i] - '0');
            }
        }
        return (positive ? res : -res);
    }
};
