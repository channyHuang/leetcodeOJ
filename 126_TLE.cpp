class Solution {
public:
    class Node {
    public:
        vector<int> next;
        int len;
        Node(int _len = INT_MAX) {
            len = _len;
        }
    };

    class QuNode {
    public:
        int len;
        vector<int> path;
    };

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> wordList) {
        maxlen = INT_MAX;
        int dlen = wordList.size();
        int beginIdx = -1, endIdx = -1;
        for (int i = 0; i < dlen; i++) {
            if (beginIdx == -1 && wordList[i] == beginWord) beginIdx = i;
            if (endIdx == -1 && wordList[i] == endWord) endIdx = i;
        }
        if (endIdx == -1) return res;
        dlen = wordList.size();
        vector<Node> nodes(dlen + 1, Node());
        for (int i = 0; i < dlen; i++) {
            if (beginIdx == -1) {
                if (similar(wordList[i], beginWord)) {
                    nodes[dlen].next.push_back(i);
                }
            }
            for (int j = i + 1; j < dlen; j++) {
                if (similar(wordList[i], wordList[j])) {
                    nodes[i].next.push_back(j);
                    nodes[j].next.push_back(i);
                }
            }
        }

        if (beginIdx == -1) {
            wordList.push_back(beginWord);
        }

        queue<QuNode> qu;
        {
            QuNode node;
            node.len = 1;
            node.path.push_back(beginIdx == -1 ? dlen : beginIdx);
            if (beginIdx == -1) {
                nodes[dlen].len = 1;
            } else {
                nodes[beginIdx].len = 1;
            }
            qu.push(node);
        }

        while (!qu.empty()) {
            QuNode node = qu.front();
            qu.pop();
            int curIdx = node.path[node.len - 1];
            if (node.len > maxlen) break;
            if (curIdx == endIdx) {
                if (maxlen > node.len) {
                    res.clear();
                    maxlen = node.len;
                }
                vector<string> substr;
                for (int i = 0; i < node.len; i++) {
                    substr.push_back(wordList[node.path[i]]);
                }
                res.push_back(substr);
                continue;
            }

            for (int i = 0; i < nodes[curIdx].next.size(); i++) {
                if (nodes[nodes[curIdx].next[i]].len <= node.len) continue;
                QuNode newNode = node;
                newNode.path.push_back(nodes[curIdx].next[i]);
                newNode.len++;
                nodes[nodes[curIdx].next[i]].len = node.len + 1;
                qu.push(newNode);
            }
        }
#ifdef DEBUG_OUTPUT
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
#endif
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
    vector<vector<string>> res;
    int maxlen;
};
