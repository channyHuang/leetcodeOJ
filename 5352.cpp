class Solution {
public:
    string generateTheString(int n) {
        if (n == 0) return "";
        if (n & 1) {
            string res;
            for (int i = 0; i < n; i++) res += "a";
            return res;
        }
        string res = "a";
        for (int i = 1; i < n; i++) res += "b";
        return res;
    }
};
