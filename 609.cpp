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
