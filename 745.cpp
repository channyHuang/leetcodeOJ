class WordFilter {
public:
    class Node {
    public:
        char c;
        Node* children[26];
        int index;
        Node(char _c = ' ') {
            c = _c;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            index = -1;
        }
    };

    WordFilter(vector<string>& words) {
        int len = words.size();
        pRoot = new Node();
        sRoot = new Node();
        for (int i = 0; i < len; i++) {
            word.push_back(words[i]);
            Node *node = pRoot;
            for (int j = 0; j < words[i].length(); j++) {
                if (node->children[words[i][j] - 'a'] == nullptr) {
                    node->children[words[i][j] - 'a'] = new Node(words[i][j] - 'a');
                }
                node = node->children[words[i][j] - 'a'];
            }
            node->index = i;

            Node* newnode = sRoot;
            for (int j = words[i].length() - 1; j >= 0; j--) {
                if (newnode->children[words[i][j] - 'a'] == nullptr) {
                    newnode->children[words[i][j] - 'a'] = new Node(words[i][j] - 'a');
                }
                newnode = newnode->children[words[i][j] - 'a'];
            }
            newnode->index = i;
        }
    }
    
    int f(string prefix, string suffix) {
        res = -1;
        Node *node = pRoot;
        int i;
        for (i = 0; i < prefix.length(); i++) {
            if (node->children[prefix[i] - 'a'] == nullptr) break;
            node = node->children[prefix[i] - 'a'];
        }
        if (i >= prefix.length()) {
            dfs(node, suffix);
        }
        return res;
    }

    void dfs(Node* node, string& suffix) {
        if (node == nullptr) return;
        if (node->index >= 0) {
            int pos = word[node->index].length() - 1;
            int i;
            for (i = suffix.length() - 1; i >= 0; i--) {
                if (pos < 0) break;
                if (word[node->index][pos] != suffix[i]) break;
                pos--;
            }
            if (i < 0) {
                res = max(res, node->index);
            }
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] == nullptr) continue;           
            dfs(node->children[i], suffix);
        }
    }

private:
    Node* pRoot = nullptr;
    Node* sRoot = nullptr;
    int res;
    vector<string> word;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
