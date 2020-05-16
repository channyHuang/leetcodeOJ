class Solution {
public:
    bool checkValidString(string s) {
        int maxleft = 0;
        int minleft = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                maxleft++;
                minleft++;
            } else if (s[i] == ')') {
                if (maxleft <= 0) return false;
                maxleft--;
                if (minleft) minleft--;
            } else {
                maxleft++;
                if (minleft) minleft--;
            }
        }
        return (minleft == 0);
    }
};
