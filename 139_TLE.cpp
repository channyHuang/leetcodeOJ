/*TLE
class Solution {
public:
    class Node {
    public:
        Node *child[256];
        bool isend;
        Node() {
            isend = false;
            for (int i = 0; i < 256; i++) {
                child[i] = NULL;
            }
        }
    };

    bool wordBreak(string s, vector<string>& wordDict) {
        int len = wordDict.size();
        if (len <= 0) return false;
        Node *root = new Node();
        for (int i = 0; i < len; i++) {
            Node *curNode = root;
            for (int j = 0; j < wordDict[i].length(); j++) {
                if (curNode->child[(unsigned char)wordDict[i][j]] == NULL) {
                    curNode->child[(unsigned char)wordDict[i][j]] = new Node();
                }
                curNode = curNode->child[(unsigned char)wordDict[i][j]];
            }
            curNode->isend = true;
        }
        return search(s, 0, s.length() - 1, root);
    }

    bool search(string s, int stPos, int endPos, Node *root) {
        if (stPos > endPos) return true;
        Node *curNode = root;
        for (int i = stPos; i <= endPos; i++) {
            if (curNode->isend) {
                if (search(s, i, endPos, root)) {
                    return true;
                }
            }
            if (curNode->child[(unsigned char)s[i]] == NULL) return false;
            curNode = curNode->child[(unsigned char)s[i]];
        }
        if (curNode->isend) return true;
        return false;
    }
};
*/
