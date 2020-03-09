class Solution {
public:
    vector<string> res;

    vector<string> letterCombinations(string digits) {
        if (digits.length() <= 0) return res;
        vector<string> maps;
        maps.resize(10);
        for (int i = 2; i <= 7; i++) {
            string s = "abcde";
            s[0] = ('a' + (i - 2) * 3);
            s[1] = ('b' + (i - 2) * 3);
            s[2] = ('c' + (i - 2) * 3);
            s[3] = 0;
            s[4] = 0;
            maps[i] = s;
        }
        maps[7][3] = 's';
        maps[8] = "tuv";
        maps[9] = "wxyz";
        res.clear();
        string str = digits;
        search(str, digits, maps, 0);
        return res;
    }

    void search(string& str, string digits, vector<string> maps, int pos) {
        if (pos >= digits.length()) {
            string subres = str;
            res.push_back(subres);
            return;
        }
        for (int i = 0; i < maps[digits[pos] - '0'].length(); i++) {
            if (maps[digits[pos] - '0'][i] == 0) continue;
            str[pos] = maps[digits[pos] - '0'][i];
            search(str, digits, maps, pos + 1);
        }
        return;
    }
};
