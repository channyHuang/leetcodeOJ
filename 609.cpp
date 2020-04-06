class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        map<string, vector<string>> maps;
        map<string, vector<string>>::iterator itr;
        int len = paths.size();
        for (int i = 0; i < len; i++) {
            string::size_type pos = paths[i].find_first_not_of(" ", 0);
            string::size_type nextPos = paths[i].find_first_of(" ", pos);
            string dir = paths[i].substr(pos, nextPos);
            pos = paths[i].find_first_not_of(" ", nextPos);
            nextPos = paths[i].find_first_of(" ", pos);
            while (pos != string::npos || nextPos != string::npos) {
                string files = paths[i].substr(pos, nextPos - pos);
                string::size_type stPos = files.find_first_of("(");
                string::size_type endPos = files.find_first_of(")");
                string contains = files.substr(stPos + 1, endPos - stPos - 1);
                files = files.substr(0, stPos);
                itr = maps.find(contains);
                if (itr == maps.end()) {
                    vector<string> sub;
                    sub.push_back(dir + "/" + files);
                    maps.insert(pair<string, vector<string>>(contains, sub));
                } else {
                    itr->second.push_back(dir + "/" + files);
                }

                pos = paths[i].find_first_not_of(" ", nextPos);
                nextPos = paths[i].find_first_of(" ", pos);                
            }
        }
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            if (itr->second.size() > 1) res.push_back(itr->second);
        }
        return res;
    }
};
/*c++14?
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        int len = paths.size();
        vector<vector<string>> res;
        map<string, vector<string>> maps;
        map<string, vector<string>>::iterator itr;
        for (int i = 0; i < len; i++) {
            regex re("[\\s()]+");
            vector<string> sub(sregex_token_iterator(paths[i].begin(), paths[i].end(), re, -1), sregex_token_iterator());
            
            for (int j = 2; j < sub.size(); j += 2) {
                itr = maps.find(sub[j]);
                if (itr != maps.end()) itr->second.push_back(string(sub[0] + "/") + sub[j - 1]);
                else {
                    vector<string> vecstr;
                    vecstr.push_back(string(sub[0] + "/") + sub[j - 1]);
                    maps.insert(pair<string, vector<string>>(sub[j], vecstr));
                }
            }
        }

        for (itr = maps.begin(); itr != maps.end(); itr++) {
            if (itr->second.size() == 1) continue;
            res.push_back(itr->second);
        }
        return res;
    }
};
*/
