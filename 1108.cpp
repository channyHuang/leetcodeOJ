class Solution {
public:
    string defangIPaddr(string address) {
        int len = address.length();
        string res;
        res.resize(len + 6);
        int pos = 0;
        for (int i = 0; i < len; i++) {
            if (address[i] != '.') {
                res[pos++] = address[i];
                continue;
            }
            res[pos++] = '[';
            res[pos++] = address[i];
            res[pos++] = ']';
        }
        return res;
    }
};
