class Solution {
public:
    string intToRoman(int num) {
        char s[20] = {0};
        int pos = 0;
        while (num) {
            if (num >= 1000) {
                num -= 1000;
                s[pos++] = 'M';
            } else if (num >= 900) {
                num -= 900;
                s[pos++] = 'C';
                s[pos++] = 'M';
            } else if (num >= 500) {
                num -= 500;
                s[pos++] = 'D';
            } else if (num >= 400) {
                num -= 400;
                s[pos++] = 'C';
                s[pos++] = 'D';
            } else if (num >= 100) {
                num -= 100;
                s[pos++] = 'C';
            } else if (num >= 90) {
                num -= 90;
                s[pos++] = 'X';
                s[pos++] = 'C';
            } else if (num >= 50) {
                num -= 50;
                s[pos++] = 'L';
            } else if (num >= 40) {
                num -= 40;
                s[pos++] = 'X';
                s[pos++] = 'L';
            } else if (num >= 10) {
                num -= 10;
                s[pos++] = 'X';
            } else if (num >= 9) {
                num -= 9;
                s[pos++] = 'I';
                s[pos++] = 'X';
            } else if (num >= 5) {
                num -= 5;
                s[pos++] = 'V';
            } else if (num >= 4) {
                num -= 4;
                s[pos++] = 'I';
                s[pos++] = 'V';
            } else if (num >= 1) {
                num--;
                s[pos++] = 'I';
            }
        }
        return string(s);
    }
};
