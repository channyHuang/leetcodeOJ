class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int len = words.size();
        int plen = pattern.length();
        vector<string> res;
        for (int i = 0; i < len; i++) {
            map<char, char> words2pattern;
            map<char, char>::iterator itr, p2witr;
            map<char, char> pattern2words;
            int slen = words[i].length();
            if (slen != plen) continue;
            int j;

            for (j = 0; j < slen; j++) {
                itr = words2pattern.find(words[i][j]);
                if (itr == words2pattern.end()) {
                    if (pattern2words.find(pattern[j]) == pattern2words.end()) {
                        words2pattern.insert(pair<char, char>(words[i][j], pattern[j]));
                        pattern2words.insert(pair<char, char>(pattern[j], words[i][j]));
                    } else break;
                } else {
                    p2witr = pattern2words.find(pattern[j]);
                    if ((p2witr == pattern2words.end()) || (p2witr->second != words[i][j])) break;
                }
            }
            if (j == slen) res.push_back(words[i]);
        }
        return res;
    }
};
