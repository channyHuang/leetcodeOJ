class Solution {
public:
    class Node {
    public:
        char c;
        Node *children[26];
        bool bTail;
        Node(char _c = ' ') {
            c = _c;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            bTail = false;
        }
    };

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int len = words.size();
        vector<string> res;
        root = new Node();
        for (int i = 0; i < len; i++) {
            Node* node = root;
            for (int j = 0; j < words[i].length(); j++) {
                if (node->children[words[i][j] - 'a'] == nullptr) {
                    node->children[words[i][j] - 'a'] = new Node(words[i][j]);
                }
                node = node->children[words[i][j] - 'a'];
            }
            node->bTail = true;
        }

        for (int i = 0; i < len; i++) {
            Node* node = root;
            bool valid = false;
            for (int j = 0; j < words[i].length(); j++) {
                if (j == words[i].length() - 1) break;
                if (node->children[words[i][j] - 'a']->bTail) {
                    Node* newNode = root;
                    valid = search(newNode, words[i], j + 1);
                }
                if (valid) break;
                node = node->children[words[i][j] - 'a'];
            }
            if (valid) {
                res.push_back(words[i]);
            }
        }
        return res;
    }

    bool search(Node *node, string& s, int stPos) {
        if (stPos >= s.length()) return node->bTail;
        bool valid = false;
        for (int j = stPos; j < s.length(); j++) {
            if (node->children[s[j] - 'a'] == nullptr) return false;
            if (node->children[s[j] - 'a']->bTail) {
                if (j == s.length() - 1) return true;
                Node *newNode = root;
                valid = search(root, s, j + 1);
            }
            if (valid) break;
            node = node->children[s[j] - 'a'];
        }
        return valid;
    }

private:
    Node *root;
};
