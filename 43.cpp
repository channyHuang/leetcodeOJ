class Solution {
public:
    string multiply(string num1, string num2) {
        int base = 0;
        string res = "0";
        for (int i = num2.length() - 1; i >= 0; i--) {
            string mulSingle = multiplySingle(num1, num2[i]);
            if (mulSingle == to_string(0)) {
                base++;
                continue;
            }
            for (int j = 0; j < base; j++) {
                mulSingle += to_string(0);
            }
            res = add(res, mulSingle);
            base++;
        }
        return res;
    }

    string multiplySingle(string num1, char c) {
        if (c == '0') return to_string(0);
        if (num1.length() == 1 && num1[0] == '0') return to_string(0);
        string res = num1;
        int add = 0;
        int tmp = 0;
        for (int i = num1.length() - 1; i >= 0; i--) {
            tmp = (num1[i] - '0') * (c - '0');
            tmp += add;
            add = 0;
            res[i] = tmp % 10 + '0';
            add = tmp / 10;
        }
        if (add) {
            res = to_string(add) + res;
        }
        return res;
    }

    string add(string a, string b) {
        string res;
        int add = 0;
        int pos = 0;
        if (a.length() >= b.length()) {
            res = a;
            pos = a.length() - 1;
            for (int i = b.length() - 1; i >= 0; i--) {
                int tmp = a[pos] - '0' - '0' + b[i] + add;
                add = 0;
                if (tmp >= 10) {
                    add = tmp / 10;
                }
                res[pos] = tmp % 10 + '0';
                pos--;
            }
        } else {
            res = b;
            pos = b.length() - 1;
            for (int i = a.length() - 1; i >= 0; i--) {
                int tmp = b[pos] - '0' - '0' + a[i] + add;
                add = 0;
                if (tmp >= 10) {
                    add = tmp / 10;
                }
                res[pos] = tmp % 10 + '0';
                pos--;
            }            
        }
        while (add) {
            if (pos < 0) return to_string(add) + res;
            res[pos] += add;
            add = 0;
            if (res[pos] - '0' >= 10) {
                add = (res[pos] - '0') / 10;
                res[pos] -= 10;   
                pos--;                 
            }
        }
        return res;
    }
};
