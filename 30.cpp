class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words.size();
        if (len <= 0) return res;
        int lenw = words[0].length();
        totalLen = lenw * len;
        if (s.length() < totalLen) return res;
        //words
        unordered_map<string, int> wordmap;
        unordered_map<string, int>::iterator itr;
        for (int i = 0; i < len; i++) {
            itr = wordmap.find(words[i]);
            if (itr == wordmap.end()) {
                wordmap.insert(pair<string, int>(words[i], 1));
            } else {
                itr->second++;
            }
        }
        //sliding window
        
        for (int i = 0, j; i <= s.length() - totalLen; i++) {
            unordered_map<string, int> smap;
            for (j = i; j < i + totalLen; j += lenw) {
                itr = smap.find(s.substr(j, lenw));
                int count = 1;
                if (itr == smap.end()) {
                    smap.insert(pair<string, int>(s.substr(j, lenw), 1));
                } else {
                    itr->second++;
                    count = itr->second;
                }

                unordered_map<string, int>::iterator witr = wordmap.find(s.substr(j, lenw));
                if (witr == wordmap.end() || witr->second < count) break;
            }
            if (j >= i + totalLen) res.push_back(i);
        }
        return res;
    }

private:
    vector<int> res;
    int totalLen;
};
