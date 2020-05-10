class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, int> maps; 
        map<string, int>::iterator itr;
        int len = paths.size();
        for (int i = 0; i < len; i++) {
            itr = maps.find(paths[i][0]);
            if (itr == maps.end()) {
                maps.insert(pair<string, int>(paths[i][0], 1));
            } else itr->second++;
            itr = maps.find(paths[i][1]);
            if (itr == maps.end()) {
                maps.insert(pair<string, int>(paths[i][1], 0));
            }
        }
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            if (itr->second == 0) return itr->first;
        }
        return "";
    }
};
