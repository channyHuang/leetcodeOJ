class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int len = accounts.size();
        map<string, int> maps;
        map<string, int>::iterator itr;
        int parents[len];
        bool used[len];
        for (int i = 0; i < len; i++) {
            parents[i] = i;
            used[i] = false;
        }
        for (int i = 0; i < len; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                itr = maps.find(accounts[i][j]);
                if (itr != maps.end()) {
                    int idx = findParent(parents, itr->second);
                    int curIdx = findParent(parents, i);
                    parents[curIdx] = idx;
                }
                else {
                    maps.insert(pair<string, int>(accounts[i][j], i));
                }
            }
        }
        vector<vector<string>> res;
        vector<set<string>> vecsets;
        vecsets.resize(len);
        for (int i = 0; i < len; i++) {
            int idx = findParent(parents, i);
            for (int j = 1; j < accounts[i].size(); j++) {
                vecsets[idx].insert(accounts[i][j]);
            }
        }
        for (int i = 0; i < len; i++) {
            if (vecsets[i].size() <= 0) continue;
            vector<string> subres;
            subres.push_back(accounts[i][0]);
            for (set<string>::iterator itr = vecsets[i].begin(); itr != vecsets[i].end(); itr++) {
                subres.push_back(*itr);
            }
            res.push_back(subres);
        }
        return res;
    }

    int findParent(int parents[], int idx) {
        while (idx != parents[idx]) idx = parents[idx];
        return idx;
    }
};
