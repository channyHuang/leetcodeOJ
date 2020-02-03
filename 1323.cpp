class Solution {
public:
    int maximum69Number (int num) {
        //1 <= num <= 10^4
        if (num / 1000 == 6) return 9000 + num % 1000;
        if (num / 100 % 10 == 6) return num / 1000 * 1000 + 900 + num % 100;
        if (num / 10 % 10 == 6) return num / 100 * 100 + 90 + num % 10;
        if (num % 10 == 6) return num + 3;
        return num;
    }
};