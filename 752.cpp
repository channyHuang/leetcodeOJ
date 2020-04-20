class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> qu;
        set<string> deadSets;
        set<string> usedSets;
        for (int i = 0; i < deadends.size(); i++) {
            if (deadends[i] == "0000") return -1;
            deadSets.insert(deadends[i]);
        }
        if (target == "0000") return 0;
        qu.push(pair<string, int>("0000", 0));
        usedSets.insert("0000");
        while (!qu.empty()) {
            pair<string, int> curPair = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                {
                    string nextStr = curPair.first;
                    nextStr[i]++;
                    if (nextStr[i] > '9') nextStr[i] = '0';
                    if (deadSets.find(nextStr) == deadSets.end()) {
                        if (nextStr == target) return curPair.second + 1;
                        if (usedSets.find(nextStr) == usedSets.end()) {
                            usedSets.insert(nextStr);
                            qu.push(pair<string, int>(nextStr, curPair.second + 1));
                        }
                    }
                }
                {
                    string nextStr = curPair.first;
                    nextStr[i]--;
                    if (nextStr[i] < '0') nextStr[i] = '9';
                    if (deadSets.find(nextStr) == deadSets.end()) {
                        if (nextStr == target) return curPair.second + 1;
                        if (usedSets.find(nextStr) == usedSets.end()) {
                            usedSets.insert(nextStr);
                            qu.push(pair<string, int>(nextStr, curPair.second + 1));
                        }
                    }
                }
            }
        }
        return -1;
    }
};
