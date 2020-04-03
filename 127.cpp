class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        if (len <= 0) return 0;
        int used[len + 1];
        map<string, int> maps;
        map<string, int>::iterator itr;
        wordList.push_back(beginWord);
        for (int i = 0; i <= len; i++) {
            used[i] = 0;
            maps.insert(pair<string, int>(wordList[i], i));
        }
        if (maps.find(endWord) == maps.end()) return 0;
        used[len] = 1;
        queue<int> qu;
        qu.push(len);
        
        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            if (nearsame(wordList[cur], endWord)) return used[cur] + 1;
            for (int i = 0; i < wordList[cur].length(); i++) {
                for (int j = 0; j < 26; j++) {
                    if (j + 'a' == wordList[cur][i]) continue;
                    string next = wordList[cur];
                    next[i] = j + 'a'; 
                    itr = maps.find(next);
                    if (itr != maps.end() && (used[itr->second] == 0)) {
                        qu.push(itr->second);
                        used[itr->second] = used[cur] + 1;
                    }
                }
            }
        }
        return 0;
    }

    bool nearsame(string a, string b) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                if (count != 0) return false;
                count = 1;
            }
        }
        if (count == 1) return true;
        return false;
    }
};
