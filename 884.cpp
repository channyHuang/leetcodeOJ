class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        int lena = A.length(), lenb = B.length();
        map<string, int> mapsa;
        map<string, int>::iterator itr;
        map<string, int> mapsb;
        int pos = 0, cur = 0;
        vector<string> res;
        while (1) {
            cur = A.find(' ', pos);
            string str;
            if (cur == string::npos) str = A.substr(pos);
            else {
                str = A.substr(pos, cur - pos);
                pos = cur + 1;
            }
            itr = mapsa.find(str);
            if (itr == mapsa.end()) mapsa.insert(make_pair(str, 1));
            else itr->second++;
            if (cur == string::npos) break;
        }
        pos = 0;
        while (1) {
            cur = B.find(' ', pos);
            string str;
            if (cur == string::npos) str = B.substr(pos);
            else {
                str = B.substr(pos, cur - pos);
                pos = cur + 1;
            }
            itr = mapsb.find(str);
            if (itr == mapsb.end()) mapsb.insert(make_pair(str, 1));
            else itr->second++;
            if (cur == string::npos) break;
        }

        for (itr = mapsa.begin(); itr != mapsa.end(); itr++) {
            if (itr->second != 1) continue;
            if (mapsb.find(itr->first) == mapsb.end()) res.push_back(itr->first);
        }
        for (itr = mapsb.begin(); itr != mapsb.end(); itr++) {
            if (itr->second != 1) continue;
            if (mapsa.find(itr->first) == mapsa.end()) res.push_back(itr->first);
        }
        return res;
    }
};
