class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name.length() > typed.length()) return false;
        if (name.length() <= 0) {
            if (typed.length() <= 0) return true;
            else return false;
        }
        int len = 0;
        for (int i = 0; i < typed.length(); i++) {
            if (len < name.length() && typed[i] == name[len]) {
                len++;
                continue;
            }
            if (len > 0 && typed[i] == name[len - 1]) continue;
            return false;
        }
        if (len < name.length()) return false;
        return true;
    }
};