class Solution {
public:
    string reformatNumber(string number) {
        string str;
        for (int i = 0; i < number.length(); i++) {
            if (number[i] == ' ' || number[i] == '-') continue;
            str += number.substr(i, 1);
        }
        int len = str.length();
        int left = len % 3;
        string res;
        for (int i = 0; i < len; i += 3) {
            if (len - i > 4) {
                res += str.substr(i, 3);
                res += "-";
            } else if (len - i == 4) {
                res += str.substr(i, 2);
                res += "-";
                res += str.substr(i + 2, 2);
                break;
            } else if (len - i <= 3) {
                res += str.substr(i);
            }
        }
        return res;
    }
};
