class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int len = d.size();
        if (len <= 0) return "";
        string res = "";
        int reslen = 0;
        sort(d.begin(), d.end());
        if (s.length() <= 0) return "";
        for (int i = 0; i < len; i++) {
            if (d[i].length() == 0) continue;
            if (reslen >= d[i].length()) continue;
            int pos = 0;
            for (int j = 0; j < s.length(); j++) {
                if (d[i][pos] == s[j]) pos++;
                if (pos >= d[i].length()) {
                    res = d[i];
                    reslen = d[i].length();
                    break;
                }
            }
        }
        return res;
    }
};
