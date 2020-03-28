class Solution {
public:
    class Node {
    public:
        Node *child[26];
        Node() {
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };

    int minimumLengthEncoding(vector<string>& words) {
        int len = words.size();
        if (len <= 0) return 0;
        if (len == 1) return words[0].length() + 1;
        sort(words.begin(), words.end(), cmp);
        Node *root = new Node();
        int res = 0;
        for (int i = 0; i < len; i++) {
            Node *curNode = root;
            bool newWord = false;
            for (int j = words[i].length() - 1; j >= 0 ; j--) {
                if (curNode->child[words[i][j] - 'a'] == NULL) {
                    curNode->child[words[i][j] - 'a'] = new Node();
                    newWord = true;
                }
                curNode = curNode->child[words[i][j] - 'a'];
            }
            if (newWord) res += words[i].length() + 1;
        }
        return res;
    }

    static bool cmp(const string& a, const string& b) {
        if (a.length() == b.length()) return a < b;
        return a.length() > b.length();
    }
};
