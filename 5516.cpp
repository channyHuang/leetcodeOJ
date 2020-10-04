class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, set<string>> maps;
        vector<string> res;
        int len = keyName.size();
        for (int i = 0; i < len; i++) {
            maps[keyName[i]].insert(keyTime[i]);
        }
        for (map<string, set<string>>::iterator itr = maps.begin(); itr != maps.end(); itr++) {
            set<string>::iterator sitr = itr->second.begin();
            set<string>::iterator nitr = sitr;
            nitr++;
            if (nitr == itr->second.end()) continue;
            for (nitr++; nitr != itr->second.end(); nitr++) {     
                if (warning(*sitr, *nitr)) {
                    res.push_back(itr->first);
                    break;
                }
                sitr++;
            }
        }
        return res;
    }

    bool warning(string a, string b) {
        int ha = (a[0] - '0') * 10 + a[1] - '0';
        int hb = (b[0] - '0') * 10 + b[1] - '0';
        if (hb > ha + 1) return false;
        int ma = (a[3] - '0') * 10 + a[4] - '0';
        int mb = (b[3] - '0') * 10 + b[4] - '0';
        return hb * 60 + mb - (ha * 60 + ma) <= 60;
    }
};
