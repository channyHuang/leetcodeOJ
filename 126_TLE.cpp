class Solution {
public:
    class Node {
    public:
        vector<int> sub;
        int len;
        vector<bool> used;
    };

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        this->endWord = endWord;
        this->beginWord = beginWord;
        int dlen = wordList.size();
        int beginIdx = -1, endIdx = -1;
        for (int i = 0; i < dlen; i++) {
            if (beginIdx == -1 && wordList[i] == beginWord) beginIdx = i;
            if (endIdx == -1 && wordList[i] == endWord) endIdx = i;
            maps[i] = vector<int>();
        }
        if (endIdx == -1) return res;
        if (beginIdx == -1) {
            wordList.push_back(beginWord);
            beginIdx = wordList.size() - 1;
        }
        dlen = wordList.size();
        for (int i = 0; i < dlen; i++) {
            for (int j = i + 1; j < dlen; j++) {
                if (similar(wordList[i], wordList[j])) {
                    maps[i].push_back(j);
                    maps[j].push_back(i);
                }
            }
        }
        maxlen = INT_MAX;
        vector<bool> used(dlen, false);
        queue<Node> qu;
        Node root;
        root.used.resize(dlen, false);
        root.sub.push_back(beginIdx);
        root.used[beginIdx] = true;
        root.len = 1;
        qu.push(root);

        while (!qu.empty()) {
            Node node = qu.front();
            qu.pop();
            if (node.len > maxlen) break;
            int curIdx = node.sub[node.len - 1];
            if (curIdx == endIdx) {
                if (maxlen > node.len) {
                    res.clear();
                    maxlen = node.len;
                }
                vector<string> substr;
                for (int i = 0; i < node.len; i++) {
                    substr.push_back(wordList[node.sub[i]]);
                }
                res.push_back(substr);
                continue;
            }
            //if (used[curIdx]) continue;
            //used[curIdx] = true;

            for (int i = 0; i < maps[curIdx].size(); i++) {
                if (node.used[maps[curIdx][i]]) continue;
                Node newNode = node;
                node.used[maps[curIdx][i]] = true;
                newNode.sub.push_back(maps[curIdx][i]);
                newNode.len++;
                qu.push(newNode);
            }
        }
/*
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }*/
        return res;
    }

    bool similar(string a, string b) {
        if (a.length() != b.length()) return false;
        int len = a.length();
        bool hasDiff = false;
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                if (hasDiff) return false;
                hasDiff = true;
            }
        }
        return hasDiff;
    }

private:
    unordered_map<int, vector<int>> maps;
    vector<vector<string>> res;
    string beginWord, endWord;
    int maxlen;
};
