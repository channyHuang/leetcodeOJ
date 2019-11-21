class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        if (n <= 0) return res;
        char newChar[2] = {0};
        if (n <= 26) {
            newChar[0] = n - 1 + 'A';
            return string(newChar);
        }
        while (n) {
            n--;
            newChar[0] = n % 26 + 'A';
            res = string(newChar) + res;
            n = n / 26;
        }
        return res;
    }
};
