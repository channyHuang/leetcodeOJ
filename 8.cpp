class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        if (len <= 0) return 0;
        int pos = 0;
        bool positive = true;
        long long res = 0;
        //[-2147483648, 2147483647]
        while (pos < len && str[pos] == ' ') pos++;
        if (pos >= len) return 0;
        if (str[pos] == '+') pos++;
        else if (str[pos] == '-') {
            positive = false;
            pos++;
        }
        while (pos < len) {
            if (!isDigit(str[pos])) break;
            res = res * 10 + str[pos] - '0';
            if (res > 2147483648) {
                if (positive) return INT_MAX;
                else return INT_MIN;
            }
            pos++;
        }
        if (res == 0) return res;
        else if (res == 2147483648 && positive) return INT_MAX;
        return (positive ? res : -res);
    }

    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }
};
