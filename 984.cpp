class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res = "";
        if (A == 0 || B == 0) {
            while (B) {
                res += "b";
                B--;
            }
            while (A) {
                res += "a";
                A--;   
            }
            return res;
        }
        if (A == B) {
            while (A) {
                if (A >= 2) {
                    res += "aabb";
                    A -= 2;
                } else {
                    res += "ab";
                    A--;
                }
            }
            return res;
        } else if (A > B) {
            while (A && B && A > B) {
                res += "aab";
                A -= 2;
                B--;
            }
            return res + strWithout3a3b(A, B);
        } else {
            while (A && B && A < B) {
                res += "bba";
                A--;
                B -= 2;
            }
            if (A == 0) {
                while (B) {
                    res += "b";
                    B--;
                }
                return res;
            } else {
                while (B) {
                    res += "ba";
                    B--;
                    A--;
                }
                return res;
            }
            return res + strWithout3a3b(A, B);
        }
        return res;
    }
};
