class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> resvec;
        bool used[105];
        memset(used, 0, sizeof(used));
        set<int> sets[2];
        set<int>::iterator itr;
        sets[0].insert(id);
        int pos = 0;
        used[id] = true;
        while (level) {
            sets[1 - pos].clear();
            for (itr = sets[pos].begin(); itr != sets[pos].end(); itr++) {
                for (int i = 0; i < friends[*itr].size(); i++) {
                    if (used[friends[*itr][i]]) continue;
                    used[friends[*itr][i]] = true;
                    sets[1 - pos].insert(friends[*itr][i]);
                }
            }
            pos = 1 - pos;
            level--;
        }
        map<string, int> resmap;
        map<string, int>::iterator itrmap;
        for (itr = sets[pos].begin(); itr != sets[pos].end(); itr++) {
            for (int i = 0; i < watchedVideos[*itr].size(); i++) {
                itrmap = resmap.find(watchedVideos[*itr][i]);
                if (itrmap == resmap.end()) {
                    resmap.insert(pair<string, int>(watchedVideos[*itr][i], 1));
                } else itrmap->second++;
            }
        }
        vector<pair<string, int>> vec;
        for (itrmap = resmap.begin(); itrmap != resmap.end(); itrmap++) {
            vec.push_back(pair<string, int>(itrmap->first, itrmap->second));
        }
        sort(vec.begin(), vec.end(), cmp);
        for (int i = 0; i < vec.size(); i++) {
            resvec.push_back(vec[i].first);
        }
        return resvec;
    }

    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
};
