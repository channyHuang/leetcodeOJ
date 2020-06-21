class Solution {
public:
    bool isMatch(string s, string p) {
        regex reg(p);
        if (regex_match(s, reg)) return true;
        return false;
    }
};
