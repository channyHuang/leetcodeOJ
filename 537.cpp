class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        string::size_type posa = a.find_first_of("+", 0);
        int reala = toint(a.substr(0, posa));
        int virtuala = toint(a.substr(posa + 1, a.length() - posa - 2));
        string::size_type posb = b.find_first_of("+", 0);
        int realb = toint(b.substr(0, posb));
        int virtualb = toint(b.substr(posb + 1, b.length() - posb - 2));
        int real = (reala * realb - virtuala * virtualb);
        int virtuall = (reala * virtualb + realb * virtuala);
        return to_string(real) + "+" + to_string(virtuall) + "i";
    }

    int toint(string s) {
        bool positive = true;
        int stPos = 0;
        if (s[0] == '-') {
            positive = false;
            stPos = 1;
        }
        int tmp = 0;
        for (; stPos < s.length(); stPos++) {
            tmp = tmp * 10 - '0' + s[stPos];
        }
        return (positive ? tmp : -tmp);
    }
};
