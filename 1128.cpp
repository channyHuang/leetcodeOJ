class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<int, int> maps;
        int res = 0;
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i][0] > dominoes[i][1]) {
                int tmp = dominoes[i][0];
                dominoes[i][0] = dominoes[i][1];
                dominoes[i][1] = tmp;
            }
            map<int, int>::iterator itr = maps.find(dominoes[i][0] * 10 + dominoes[i][1]);
            if (itr == maps.end()) {
                maps.insert(make_pair(dominoes[i][0] * 10 + dominoes[i][1], 1));
            } else {
                itr->second++;
            }
        }
        map<int, int>::iterator itr = maps.begin();
        for (; itr != maps.end(); itr++) {
            res += itr->second * (itr->second - 1) / 2;
        }
        return res;
    }
};
