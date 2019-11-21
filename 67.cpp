class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int add = 0;
        int posa = a.length() - 1;
        int posb = b.length() - 1;
        while ((posa >= 0) && (posb >= 0)) {
            int sum = a[posa--] - '0' + b[posb--] - '0' + add;
            add = 0;
            //sum = 0, 1, 2, 3
            if (sum == 0) res = "0" + res;
            else if (sum == 1) res = "1" + res;
            else if (sum == 2) {
                add = 1;
                res = "0" + res;
            } else {
                add = 1;
                res = "1" + res;
            }
        }

        while(posa >= 0) {
            int sum = a[posa--] - '0' + add;
            add = 0;
            //sum = 0, 1, 2
            if (sum == 0) res = "0" + res;
            else if (sum == 1) res = "1" + res;
            else if (sum == 2) {
                add = 1;
                res = "0" + res;
            }
        }

        while(posb >= 0) {
            int sum = b[posb--] - '0' + add;
            add = 0;
            //sum = 0, 1, 2
            if (sum == 0) res = "0" + res;
            else if (sum == 1) res = "1" + res;
            else if (sum == 2) {
                add = 1;
                res = "0" + res;
            }
        }

        if (add) res = "1" + res;

        return res;
    }


};
