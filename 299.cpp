class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.length();
        int count[10] = {0};
        int resA = 0, resB = 0;
        string res = "";
        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                resA++;
                continue;
            }
            if (count[secret[i] - '0'] < 0) resB++;
            count[secret[i] - '0']++;
            if (count[guess[i] - '0'] > 0) resB++;
            count[guess[i] - '0']--;
        }
        return res + itoa(resA) + "A" + itoa(resB) + "B";
    }

    string itoa(int n) {
        string res = "";
        if (n == 0) return "0";
        char str[2] = {0};
        while (n) {
            str[0] = n % 10 + '0';
            res = string(str) + res;
            n /= 10;
        }
        return res;
    }
};
