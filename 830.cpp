class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int pos = 0, i = 0;
        vector<vector<int>> res;
        map<string, vector<int>> maps;
        map<string, vector<int>>::iterator itr;
        for (i = 1; i < S.length(); i++) {
            if (S[i] == S[pos]) continue;
            if (i - pos < 3) {
                pos = i;
                continue;
            }
            itr = maps.find(S.substr(pos, i - pos));
            if (itr != maps.end()) {
                itr->second[2]++;
                pos = i;
                continue;
            }
            vector<int> index;
            index.push_back(pos);
            index.push_back(i - 1);
            index.push_back(1);
            maps.insert(make_pair(S.substr(pos, i - pos), index));
            pos = i;
        }
        if (i - pos >= 3) {
            itr = maps.find(S.substr(pos, i - pos));
            if (itr != maps.end()) {
                itr->second[2]++;
            } else {
                vector<int> index;
                index.push_back(pos);
                index.push_back(i - 1);
                index.push_back(1);
                maps.insert(make_pair(S.substr(pos, i - pos), index));
            }
        }
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            for (int i = 0; i < itr->second[2]; i++) {
                vector<int> index;
                index.push_back(itr->second[0]);
                index.push_back(itr->second[1]);
                res.push_back(index);
            }
        }
        return res;
    }
};
