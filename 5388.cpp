class Solution {
public:
    string reformat(string s) {
        int len = s.length();
        int cnt = 0;
        string res = s + " ";
        int pos = -1;
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                res[cnt * 2] = s[i];
                if (cnt * 2 >= len) return "";
                cnt++;
            } else {
                pos += 2;
                if (((len & 1) == 0) && (pos >= len)) return "";
                if (((len & 1) == 1) && (pos > len)) return "";
                res[pos] = s[i];
            }
        }
        if ((len & 1) == 0) return res.substr(0, len);
        if (pos < len) return res.substr(0, len);
        res[pos - 1] = res[0];
        return res.substr(1, len);
    }
};
