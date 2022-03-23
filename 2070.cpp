class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int qlen = queries.size();
        vector<int> res(qlen, 0);
        map<int, int> maps;
        int ilen = items.size();
        for (int i = 0; i < ilen; ++i) {
            if (maps.find(items[i][0]) == maps.end()) {
                maps[items[i][0]] = items[i][1];
            } else {
                maps[items[i][0]] = std::max(maps[items[i][0]], items[i][1]);
            }
        }
        map<int, vector<int>> qu;
        for (int i = 0; i < qlen; ++i) {
            qu[queries[i]].push_back(i);
        }
        auto mitr = maps.begin();
        int count = 0;
        for (auto itr = qu.begin(); itr != qu.end(); itr++) {
             while (mitr != maps.end() && (mitr->first <= itr->first)) {
                count = std::max(mitr->second, count);
                mitr++;
             }
             for (int i = 0; i < itr->second.size(); ++i) {
                res[itr->second[i]] = count;
             }
        }
        return res;
    }
};

