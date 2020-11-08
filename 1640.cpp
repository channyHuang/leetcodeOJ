class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int alen = arr.size();
        int plen = pieces.size();
        unordered_map<int, int> pmaps;
        for (int i = 0; i < plen; i++) {
            if (pieces[i].size() <= 0) continue;
            pmaps[pieces[i][0]] = i;
        }

        int apos = 0;
        while (apos < alen) {
            unordered_map<int, int>::iterator itr = pmaps.find(arr[apos]);
            if (itr == pmaps.end()) return false;
            int pidx = itr->second;
            if (apos + pieces[pidx].size() > alen) return false;
            for (int i = 0; i < pieces[pidx].size(); i++) {
                if (arr[apos + i] != pieces[pidx][i]) return false;
            }
            apos += pieces[pidx].size();
        }
        return true;
    }
};
