class Solution {
public:
    string convertToBase7(int num) {
        string res;
        bool negitive = false;
        if (num == 0) return "0";
        if (num < 0) {
            negitive = true;
            num = -num;
        }
        char tmp[2] = {0};
        while (num) {
            tmp[0] = num % 7 + '0';
            res = string(tmp) + res;
            num /= 7;
        }
        if (negitive) res = "-" + res;
        return res;
    }
};
