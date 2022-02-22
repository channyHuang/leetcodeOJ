class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int slen = s.length();
        int strlen = slen - 2;
        vector<string> res;
        for (int i = 1; i < strlen; ++i) {
            vector<string> left = seperate(s.substr(1, i), i);
            vector<string> right = seperate(s.substr(i + 1, strlen - i), strlen - i);

            for (int x = 0; x < left.size(); ++x) {
                for (int y = 0; y < right.size(); ++y) {
                    res.push_back("(" + left[x] + ", " + right[y] + ")");
                }
            }
        }
        return res;
    }

    vector<string> seperate(const string &s, int len) {
        vector<string> res;
        if (len <= 0) return res;
        if (len == 1) {
            res.push_back(s);
            return res;
        }
        // origin
        if (s[0] != '0') res.push_back(s);
        else {
            if (s[1] == '0') {
                if (len == 2) return res;
                if (s[len - 1] == '0') return res;
                string str = s.substr(0, 1) + "." + s.substr(1);
                res.push_back(str);
                return res;
            }
            if (s[len - 1] == '0') return res;
            string str = s.substr(0, 1) + "." + s.substr(1);
            res.push_back(str);
            return res;
        }
        if (s[len - 1] == '0') return res;
        // add point
        for (int i = 1; i < len; ++i) {// point after s[i]
            string str = s.substr(0, i) + "." + s.substr(i);
            res.push_back(str);
        }
        return res;
    }
};
