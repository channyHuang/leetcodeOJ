class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.length();
        for (int i = 1; i <= len - 2; i++) {
            if (num[0] == '0' && i != 1) break;
            for (int j = i + 1; j <= len - 1; j++) {
                if (num[i] == '0' && j != i + 1) break;
                search(num, i, j, add(num.substr(0, i), num.substr(i, j - i)));
                if (flag) return flag;
            }
        }
        return flag;
    }

    void search(string num, int pos1, int pos2, string next) {
        if (next.length() > num.length() - pos2) return;
        if (num.substr(pos2, next.length()) != next) return;
        if (next.length() == num.length() - pos2) {
            flag = true;
            return;
        }
        search(num, pos2, pos2 + next.length(), add(num.substr(pos1, pos2 - pos1), next));
    }

    string add(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        int add = 0;
        if (lena >= lenb) {
            int pos = lena - 1;
            for (int i = lenb - 1; i >= 0; i--) {
                a[pos] += (b[i] - '0') + add;
                add = 0;
                if (a[pos] > '9') {
                    a[pos] -= 10;
                    add = 1;
                }
                pos--;
            }
            while (add) {
                if (pos < 0) {
                    a = "1" + a;
                    add = 0;
                }
                else {
                    a[pos]++;
                    add = 0;
                    if (a[pos] > '9') {
                        a[pos] -= 10;
                        add = 1;
                    }
                    pos--;
                }
            }
            return a;
        }
        int pos = lenb - 1;
        for (int i = lena - 1; i >= 0; i--) {
            b[pos] += (a[i] - '0') + add;
            add = 0;
            if (b[pos] > '9') {
                b[pos] -= 10;
                add = 1;
            }
            pos--;
        }
        while (add) {
            if (pos < 0) {
                b = "1" + b;
                add = 0;
            }
            else {
                b[pos]++;
                add = 0;
                if (b[pos] > '9') {
                    b[pos] -= 10;
                    add = 1;
                }
                pos--;
            }
        }
        return b;
    }

private:
    bool flag;
};
