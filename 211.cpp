class WordDictionary {
public:
    class Node {
    public:
        char c;
        Node *children[26];
        bool isend;
        Node (char _c = ' ') {
            c = _c; 
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isend = false;
        }
    };  
    Node *root;

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int len = word.length();
        Node *curNode = root;
        for (int i = 0; i < len; i++) {
            if (curNode->children[word[i] - 'a'] == NULL) curNode->children[word[i] - 'a'] = new Node(word[i] - 'a'); 
            curNode = curNode->children[word[i] - 'a'];
        }
        curNode->isend = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int len = word.length();
        Node *curNode = root;
        for (int i = 0; i < len; i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (curNode->children[j] == NULL) continue;
                    if( search(word.substr(i + 1), curNode->children[j]) ) return true;
                }
                return false;
            } else {
                if (curNode->children[word[i] - 'a'] == NULL) return false;
                curNode = curNode->children[word[i] - 'a'];
            }
        }
        return curNode->isend;
    }

    bool search(string word, Node *node) {
        int len = word.length();
        Node *curNode = node;
        for (int i = 0; i < len; i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (curNode->children[j] == NULL) continue;
                    if( search(word.substr(i + 1), curNode->children[j]) ) return true;
                }
                return false;
            } else {
                if (curNode->children[word[i] - 'a'] == NULL) return false;
                curNode = curNode->children[word[i] - 'a'];
            }
        }
        return curNode->isend;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
