class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, int> maps;
        unordered_map<string, int>::iterator itr;
        int len = bank.size();
        vector<bool> used(len, false);
        for (int i = 0; i < len; i++) {
            maps.insert(pair<string, int>(bank[i], i));
        }
        itr = maps.find(start);
        if (itr == maps.end()) {
            maps.insert(pair<string, int>(start, len));
            used.push_back(true);
        } else {
            used[itr->second] = true;
        }
        if (maps.find(end) == maps.end()) return -1;
        queue<pair<string, int>> qu;
        qu.push(pair<string, int>(start, 0));
        vector<char> ch;
        ch.push_back('A');
        ch.push_back('C');
        ch.push_back('G');
        ch.push_back('T');
        while (!qu.empty()) {
            pair<string, int> cur = qu.front();
            qu.pop();
            if (cur.first == end) return cur.second;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    string sub = cur.first;
                    sub[i] = ch[j];
                    itr = maps.find(sub);
                    if (itr == maps.end()) continue;
                    if (used[itr->second]) continue;
                    qu.push(pair<string, int>(sub, cur.second + 1));
                    used[itr->second] = true;
                }
            }
        }
        return -1;
    }
};
