class StreamChecker {
public:
    class Node {
    public:
        char c;
        Node* children[26];
        bool bTail;
        Node(char _c = ' ') {
            c = _c;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            bTail = false;
        } 
    };

    StreamChecker(vector<string>& words) {
        int len = words.size();
        root = new Node();
        for (int i = 0; i < len; i++) {
            Node *node = root;
            for (int j = words[i].length() - 1; j >= 0; j--) {
                if (node->children[words[i][j] - 'a'] == nullptr) {
                    node->children[words[i][j] - 'a'] = new Node(words[i][j]);
                }
                node = node->children[words[i][j] - 'a'];
            }
            node->bTail = true;
        }
        pos = 0;
    }
    
    bool query(char letter) {
        vec.push_back(letter);
        pos++;
        Node *node = root;
        for (int i = pos - 1; i >= 0; i--) {
            if (node->children[vec[i] - 'a'] == nullptr) break;
            if (node->children[vec[i] - 'a']->bTail) return true;
            node = node->children[vec[i] - 'a'];
        }
        return false;
    }
private:
    Node *root;
    vector<char> vec;
    int pos;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
