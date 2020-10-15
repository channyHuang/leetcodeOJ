class Solution {
public:
    int minJumps(vector<int>& arr) {
        int len = arr.size();
        if (len == 1) return 0;
        vector<int> minStep(len, INT_MAX);
        for (int i = 0; i < len; i++) {
            sameidx[arr[i]].insert(i);
        }
        queue<pair<int, int>> qu;
        qu.push(pair<int, int>(0, 0));
        minStep[0] = 0;
        while (!qu.empty()) {
            pair<int,int> cur = qu.front();
            qu.pop();
            //cout << cur.first << " " << cur.second << endl;
            if (cur.first == len - 1) {
                return cur.second;
            }
            if ((cur.first < len - 1) && (minStep[cur.first + 1] == INT_MAX)) {
                minStep[cur.first + 1] = cur.second + 1;
                qu.push(pair<int, int>(cur.first + 1, cur.second + 1));
            }
            if ((cur.first > 0) && (minStep[cur.first - 1] == INT_MAX)) {
                minStep[cur.first - 1] = cur.second + 1;
                qu.push(pair<int, int>(cur.first - 1, cur.second + 1));
            }
            unordered_map<int, unordered_set<int>>::iterator itr = sameidx.find(arr[cur.first]);
            if (itr != sameidx.end()) {
                for (unordered_set<int>::iterator sitr = itr->second.begin(); sitr != itr->second.end(); sitr++) {
                    if (*sitr == cur.first || (minStep[*sitr] != INT_MAX)) continue;
                    minStep[*sitr] = cur.second + 1;
                    qu.push(pair<int, int>(*sitr, cur.second + 1));
                }
                sameidx.erase(itr);
            }
        }
        return -1;
    }
private:
    unordered_map<int, unordered_set<int>> sameidx;
    int len;
};
