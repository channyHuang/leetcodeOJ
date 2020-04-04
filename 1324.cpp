class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> words;
        vector<string> res;
        int maxLen = 0;
        int idx = 0;
        string::size_type pos = s.find_first_not_of(" ", 0);
        string::size_type nextPos = s.find_first_of(" ", pos);
        while (pos != string::npos || nextPos != string::npos) {
            words.push_back(s.substr(pos, nextPos - pos));
            int tmpPos = words.size() - 1;
            if (maxLen < words[tmpPos].length()) {
                maxLen = words[tmpPos].length();
                idx = tmpPos;
            }
            pos = s.find_first_not_of(" ", nextPos);
            nextPos = s.find_first_of(" ", pos);
        }
        res.resize(maxLen);
        for (int i = 0; i < maxLen; i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i >= words[j].length()) {
                    //if (j < idx) res[i] += " ";
                    //else continue;
                    res[i] += " ";
                } else res[i] += words[j].substr(i, 1);
            }
        }
        for (int i = 0; i < maxLen; i++) {
            int j = res[i].length() - 1;
            while (j >= 0 && res[i][j] == ' ') j--;
            res[i][j + 1] = 0;
        }
        return res;
    }
};
