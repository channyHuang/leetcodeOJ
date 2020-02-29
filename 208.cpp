class Trie {
public:
    class Node {
    public:
        char c;
        Node *children[26];
        bool isend;
        Node(char _c = ' ') {
            c = _c;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isend = false;
        }
    };
    Node *root;

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int len = word.length();
        Node *curNode = root;
        for (int i = 0; i < len; i++) {
            if (curNode->children[word[i] - 'a'] == NULL) curNode->children[word[i] - 'a'] = new Node(word[i] - 'a');
            curNode = curNode->children[word[i] - 'a'];
        }
        curNode->isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int len = word.length();
        Node *curNode = root;
        for (int i = 0; i < len; i++) {
            if (curNode->children[word[i] - 'a'] == NULL) return false;
            curNode = curNode->children[word[i] - 'a'];
        }
        return curNode->isend;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int len = prefix.length();
        Node *curNode = root;
        for (int i = 0; i < len; i++) {
            if (curNode->children[prefix[i] - 'a'] == NULL) return false;
            curNode = curNode->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
