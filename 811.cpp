class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        map<string, int> maps;
        map<string, int>::iterator itr;
        for (int i = 0; i < cpdomains.size(); i++) {
            int pos = cpdomains[i].find(' ');
            int count = atoi(cpdomains[i].substr(0, pos));
            string domain = cpdomains[i].substr(pos + 1);
            while (1) {
                itr = maps.find(domain);
                if (itr == maps.end()) {
                    maps.insert(make_pair(domain, count));
                } else {
                    itr->second += count;
                }
                pos = domain.find('.');
                if (pos == string::npos) break;
                domain = domain.substr(pos + 1);
            }
        }
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            res.push_back(itoa(itr->second) + " " + itr->first);
        }
        return res;
    }

    int atoi(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            res = res * 10 + s[i] - '0';
        }
        return res;
    }

    string itoa(int n) {
        char tmp[15] = {0};
        int pos = 12;
        while (n) {
            tmp[--pos] = n % 10 + '0';
            n /= 10;
        }
        int len = 0;
        while (tmp[pos] != 0) {
            tmp[len++] = tmp[pos++];
        }
        tmp[len] = 0;
        return string(tmp);
    }
};
