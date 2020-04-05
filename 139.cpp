class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> maps;
        for (int i = 0; i < wordDict.size(); i++) {
            maps.insert(pair<string, int>(wordDict[i], 1));
        }
        int len = s.length();
        bool dp[len + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && maps.find(s.substr(j, i - j)) != maps.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};
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
        if (s.length() <= 0) return true;
        bool has[255];
        memset(has, 0, sizeof(has));
        Node *root = new Node();
        for (int i = 0; i < len; i++) {
            Node *curNode = root;
            for (int j = 0; j < wordDict[i].length(); j++) {
                has[(unsigned char)wordDict[i][j]] = true;
                if (curNode->child[(unsigned char)wordDict[i][j]] == NULL) {
                    curNode->child[(unsigned char)wordDict[i][j]] = new Node();
                }
                curNode = curNode->child[(unsigned char)wordDict[i][j]];
            }
            curNode->isend = true;
        }
        for (int i = 0; i < s.length(); i++) {
            if (!has[(unsigned char)s[i]]) return false;
        }
        return search(s, 0, s.length() - 1, root);
    }

    bool search(string s, int stPos, int endPos, Node *root) {
        if (stPos > endPos) return true;
        
        queue<int> index;
        index.push(stPos);
        while (!index.empty()) {
            int idx = index.front();
            index.pop();
            Node *curNode = root;
            for (int i = idx; i <= endPos; i++) {
                if (curNode->isend) {
                    index.push(i);
                }
                if (curNode->child[(unsigned char)s[i]] == NULL) break;
                curNode = curNode->child[(unsigned char)s[i]];
                if (i == endPos && curNode->isend) return true;
            }
        }
        return false;
    }
};
*/
