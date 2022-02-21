class Solution {
public:
    class Node {
    public:
        int len;
        Node *children[26];
        Node() : len(0) {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        } 
    };

    int respace(vector<string>& dictionary, string sentence) {
        int dlen = dictionary.size();
        Node *root = new Node();
        for (int i = 0; i < dlen; ++i) {
            Node *cur = root;
            for (int j = 0; j < dictionary[i].length(); ++j) {
                if (cur->children[dictionary[i][j] - 'a'] == nullptr) {
                    cur->children[dictionary[i][j] - 'a'] = new Node();
                }
                cur = cur->children[dictionary[i][j] - 'a'];
            }
            cur->len = dictionary[i].length();
        }
        int len = sentence.length();
        vector<int> maxn(len + 1, 0);
        for (int i = len - 1; i >= 0; --i) {
            maxn[i] = maxn[i + 1];
            Node *cur = root;
            int pos = i;
            while (pos < len) {
                if (cur->children[sentence[pos] - 'a'] != nullptr) {
                    cur = cur->children[sentence[pos] - 'a'];
                    if (cur->len > 0) {
                        maxn[i] = std::max(maxn[i], cur->len + maxn[i + cur->len]);
                    }
                } else {
                    break;
                }
                pos++;
            }
            if (cur->len > 0) {
                maxn[i] = std::max(maxn[i], cur->len + maxn[i + cur->len]);
            }
        }
        return len - maxn[0];
    }
};
