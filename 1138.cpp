class Solution {
public:
    string alphabetBoardPath(string target) {
        int len = target.length();
        string res = "";
        int r = 0, c = 0;
        int nr = 0, nc = 0;
        for (int i = 0; i < len; i++) {
            calc(target[i], nr, nc);
            while (nr < r) {
                res += "U";
                r--;
            }
            while (nc < c) {
                res += "L";
                c--;
            }
            while (nr > r) {
                res += "D";
                r++;
            }
            while (nc > c) {
                res += "R";
                c++;
            }
            res += "!";
            r = nr;
            c = nc;
        }
        return res;
    }

    void calc(char _c, int& r, int& c) {
        int tmp = _c - 'a';
        r = tmp / 5;
        c = tmp % 5;
    }
};
