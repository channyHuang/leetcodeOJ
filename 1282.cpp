class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        int count = 0;
        map<int, int> maps;
        map<int, int>::iterator itr;
        for (int i = 0; i < groupSizes.size(); i++) {
            itr = maps.find(groupSizes[i]);
            if (itr == maps.end()) {
                maps.insert(make_pair(groupSizes[i], count++));
                vector<int> subres;
                subres.push_back(i);
                res.push_back(subres);
            } else {
                if (res[itr->second].size() >= itr->first) {
                    itr->second = count++;
                    vector<int> subres;
                    subres.push_back(i);
                    res.push_back(subres);
                } else {
                    res[itr->second].push_back(i);
                }
            }
        }
        return res;
    }
};
