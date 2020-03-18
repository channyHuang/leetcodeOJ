class Solution {
public:
    vector<string> res;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int len = tickets.size();
        
        if (len <= 0) return res;
        map<string, vector<string>> maps;
        map<string, vector<bool>> used;
        map<string, vector<string>>::iterator itr;
        map<string, vector<bool>>::iterator useditr;
        for (int i = 0; i < len; i++) {
            itr = maps.find(tickets[i][0]);
            if (itr == maps.end()) {
                vector<string> subres;
                subres.push_back(tickets[i][1]);
                vector<bool> subused;
                subused.push_back(false);
                maps.insert(pair<string, vector<string>>(tickets[i][0], subres));
                used.insert(pair<string, vector<bool>>(tickets[i][0], subused));
            } else {
                useditr = used.find(tickets[i][0]);
                itr->second.push_back(tickets[i][1]);
                useditr->second.push_back(false);
            }
        }
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            sort(itr->second.begin(), itr->second.end());
        }
        vector<string> path;
        path.push_back("JFK");
        search(path, maps, used, len, 1);
        return res;
    }

    void search(vector<string>& path, map<string, vector<string>> maps, map<string, vector<bool>> used, int len, int pos) {
        if (pos == len + 1) {
            bool replace = false;
            for (int i = 0; i < pos; i++) {
                if (res.size() < pos)
                    res.push_back(path[i]);
                else if (replace) res[i] = path[i];
                else if (res[i] < path[i]) break;
                else if (res[i] > path[i]) {
                    replace = true;
                    res[i] = path[i];
                }
            }
            return;
        }
        if (res.size() > 0) {
            return;
        }
        map<string, vector<string>>::iterator itr = maps.find(path[pos - 1]);
        if (itr == maps.end()) return;
        map<string, vector<bool>>::iterator useditr = used.find(path[pos - 1]);
        for (int i = 0; i < itr->second.size(); i++) {
            if (useditr->second[i]) continue;
            useditr->second[i] = true;
            if (path.size() <= pos) path.push_back(itr->second[i]);
            else path[pos] = itr->second[i];
            search(path, maps, used, len, pos + 1);
            if (res.size() > 0) return;
            useditr->second[i] = false;
        }
    }
};
