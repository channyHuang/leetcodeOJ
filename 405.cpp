class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int n = num;
        string res = "";
        int mod = 0;
        char toStr[2] = {0};
        while (n) {
            mod = n % 16;
            if (mod < 10) toStr[0] = mod + '0';
            else toStr[0] = mod - 10 + 'a';
            res = string(toStr) + res;
            n >>= 4;
        }
        return res;
    }
};
