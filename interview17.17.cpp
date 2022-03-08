class Solution {
public:
    struct Node {
        Node *children[26];
        int index;

        Node() : index(-1) {
            for (int i = 0; i < 26; ++i) {
                children[i] = nullptr;
            }
        }
    };

    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        int slen = smalls.size();
        vector<vector<int>> res(slen);
        int blen = big.length();
        Node *root = new Node();
        for (int i = 0; i < slen; ++i) {
            Node *cur = root;
            for (int j = 0; j < smalls[i].length(); ++j) {
                if (cur->children[smalls[i][j] - 'a'] == nullptr) {
                    cur->children[smalls[i][j] - 'a'] = new Node();
                }
                cur = cur->children[smalls[i][j] - 'a'];
            }
            cur->index = i;
        }
        for (int i = 0; i < blen; ++i) {
            Node *cur = root;
            int pos = i;
            while (cur != nullptr) {
                if (cur->children[big[pos] - 'a'] == nullptr) break;
                cur = cur->children[big[pos] - 'a'];
                if (cur->index != -1) {
                    res[cur->index].push_back(i);
                }
                pos++;
                if (pos >= blen) break;
            }
        }
        return res;
    }
};
