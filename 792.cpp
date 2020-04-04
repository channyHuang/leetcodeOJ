class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        map<string, int> maps;
        map<string, int>::iterator itr;
        for (int i = 0; i < words.size(); i++) {
            itr = maps.find(words[i]);
            if (itr != maps.end()) {
                res += itr->second;
                continue;
            }
            int pos = 0, j;
            for (j = 0; j < S.length(); j++) {
                if (S[j] == words[i][pos]) {
                    pos++;
                }
                if (pos >= words[i].length()) break;
            }
            if (j < S.length()) {
                res++;
                maps.insert(pair<string, int>(words[i], 1));
            } else {
                maps.insert(pair<string, int>(words[i], 0));
            }
        }
        return res;
    }
};
