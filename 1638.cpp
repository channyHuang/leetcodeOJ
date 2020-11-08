class Solution {
public:
    int countSubstrings(string s, string t) {
        slength = s.length();
        tlength = t.length();
        vector<map<string, int>> substrings(110);
        vector<map<string, int>> substringt(110);
        calcSubstr(s, substrings);
        calcSubstr(t, substringt);
        int minlen = min(slength, tlength);
        int res = 0;
        for (int i = 1; i <= minlen; i++) { //substr length
            for (map<string, int>::iterator itr = substrings[i].begin(); itr != substrings[i].end(); itr++) {
                for (map<string, int>::iterator nitr = substringt[i].begin(); nitr != substringt[i].end(); nitr++) {
                    if (similar(itr->first, nitr->first)) {
                        res += (itr->second * nitr->second);
                    }
                }
            }
        }
        return res;
    }

    void calcSubstr(string s, vector<map<string, int>>& substrings) {
        int slen = s.length();
        for (int i = 0; i < slen; i++) {
            for (int j = 1; j <= slen - i; j++) {
                string tmps = s.substr(i, j);
                map<string, int>::iterator itr = substrings[j].find(tmps);
                if (itr == substrings[j].end()) {
                    substrings[j][tmps] = 1;
                } else {
                    itr->second++;
                }
            }
        }
    }

    bool similar(const string& a, const string& b) {
        int len = a.length();
        int diff = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff >= 2) return false;
            }
        }
        return (diff == 1);
    }

private:
    int slength, tlength;
};
