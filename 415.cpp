class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        string res = (len1 > len2 ? num1 : num2);
        int pos1 = len1 - 1, pos2 = len2 - 1;
        int len = (len1 > len2 ? len1 : len2);
        while (pos1 >= 0 && pos2 >= 0) {
            res[--len] = num1[pos1--] - '0' + num2[pos2--] ;
        }
        while (pos1 >= 0) res[--len] = num1[pos1--];
        while (pos2 >= 0) res[--len] = num2[pos2--];
        int add = 0;
        len = (len1 > len2 ? len1 : len2);
        for (int i = len - 1; i >= 0; i--) {
            res[i] += add;
            if (res[i] >= '0' + 10) {
                res[i] -= 10;
                add = 1;
            } else add = 0;
        }

        if (add) res = "1" + res;
        return res;
    }
};
