class Solution {
public:
    string toLowerCase(string str) {
        string res;
        int len = str.length();
        res.resize(len);
        for (int i = 0; i < len; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') res[i] = str[i] - 'A' + 'a';
            else res[i] = str[i];
        }
        return res;
    }
};
