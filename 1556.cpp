class Solution {
public:
    string thousandSeparator(int n) {
        if (n == 0) return "0";
        char s[15];
        int pos = 0;
        int cnt = 0;

        while (n) {
            s[pos++] = (n % 10 + '0');
            n /= 10; 
            cnt++;
            if (cnt == 3 && n) {
                s[pos++] = '.';
                cnt = 0;
            } 
        }
        for (int i = 0; i < pos / 2; i++) {
            char tmp = s[i];
            s[i] = s[pos - i - 1];
            s[pos - i - 1] = tmp;
        }
        s[pos] = '\0';
        return s;
    }
};
