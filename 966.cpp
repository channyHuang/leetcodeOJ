class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int lenw = wordlist.size();
        int lenq = queries.size();
        vector<string> res;
        res.resize(lenq);
        map<string, int> sameMaps;
        map<string, int> maps;
        map<string, int> aeiouMaps;
        map<string, int>::iterator itr;
        for (int i = 0; i < lenw; i++) {
            sameMaps.insert(pair<string, int>(wordlist[i], i));
            string astr = wordlist[i];
            string str = wordlist[i];
            for (int j = 0; j < wordlist[i].length(); j++) {
                if (aeiou(astr[j])) astr[j] = ' ';
                if (str[j] >= 'A' && str[j] <= 'Z') {
                    str[j] = str[j] - 'A' + 'a';
                    if (astr[j] != ' ') astr[j] = astr[j] - 'A' + 'a';
                }
            }
            maps.insert(pair<string, int>(str, i));
            aeiouMaps.insert(pair<string, int>(astr, i));
        }
        for (int i = 0; i < lenq; i++) {
            itr = sameMaps.find(queries[i]);
            if (itr != sameMaps.end()) {
                res[i] = wordlist[itr->second];
                continue;
            }
            string s = queries[i];
            string as = queries[i];
            for (int j = 0; j < s.length(); j++) {
                if (aeiou(as[j]) ) as[j] = ' ';
                if (s[j] >= 'A' && s[j] <= 'Z') {
                    s[j] = s[j] - 'A' + 'a';
                    if (as[j] != ' ') as[j] = as[j] - 'A' + 'a';
                }
                
            }
            itr = maps.find(s);
            if (itr != maps.end()) {
                res[i] = wordlist[itr->second];
                continue;
            }
            itr = aeiouMaps.find(as);
            if (itr != aeiouMaps.end()) {
                res[i] = wordlist[itr->second];
                continue;
            }
            res[i] = "";
        }
        return res;
    }

    bool same(string dis, string target) {
        int len = dis.length();
        if (target.length() != len) return false;
        for (int i = 0; i < len; i++) {
            bool adis = aeiou(dis[i]);
            bool atar = aeiou(target[i]);
            if (adis && atar) continue;
            if (adis || atar) return false;
            if (dis[i] >= 'A' && dis[i] <= 'Z') dis[i] = dis[i] - 'A' + 'a';
            if (target[i] >= 'A' && target[i] <= 'Z') target[i] = target[i] - 'A' + 'a';
            if (dis[i] != target[i]) return false;
        }
        return true;
    }

    bool aeiou(char c) {
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};
