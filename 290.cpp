class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string dic[26];
        map<string, char> maps;
        int lenp = pattern.length();
        int pos = 0, next = 0;
        for (int i = 0; i < lenp; i++) {
            next = str.find(' ', pos);
            string word;
            if (next == string::npos) {
                if (i != lenp - 1) return false;
                word = str.substr(pos);
            } else {
                word = str.substr(pos, next - pos);
            }
            if (dic[pattern[i] - 'a'] == "") {
                if (maps.find(word) != maps.end()) return false;
                dic[pattern[i] - 'a'] = word;
                maps.insert(make_pair(word, pattern[i]));
            }
            else if (dic[pattern[i] - 'a'] != word) return false;
            pos = next + 1;
        }
        if (next != string::npos) return false;
        return true;
    }
};
