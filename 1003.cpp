class Solution {
public:
    bool isValid(string S) {
        string::size_type pos = S.find("abc", 0);
        while (pos != string::npos) {
            S.replace(pos, 3, "");
            pos = S.find("abc", 0);
        }
        return S == "";
    }
};
