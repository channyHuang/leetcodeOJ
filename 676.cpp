class MagicDictionary {
public:
    class Node {
    public:
        char c;
        Node *child[26];
        bool isend;
        Node(char _c = ' ') {
            c = _c; 
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
            isend = false;
        }
    };  
    Node *root;

    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new Node();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        int len = dict.size();
        for (int i = 0; i < len; i++) {
            Node *curNode = root;
            int slen = dict[i].length();
            for (int j = 0; j < slen; j++) {
                if (curNode->child[dict[i][j] - 'a'] == NULL) curNode->child[dict[i][j] - 'a'] = new Node(dict[i][j]);
                curNode = curNode->child[dict[i][j] - 'a'];
            }
            curNode->isend = true;
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int len = word.length();
        for (int i = 0; i < len; i++) {
            Node *curNode = root;
            int j;
            for (j = 0; j < len; j++) {
                if (j == i) {
                    for (int x = 0; x < 26; x++) {
                        if (curNode->child[x] == NULL || (x == word[i] - 'a')) continue;
                        if (search(word.substr(i + 1), curNode->child[x])) return true;
                    }
                    break;
                } else {
                    if (curNode->child[word[j] - 'a'] == NULL) break;
                    curNode = curNode->child[word[j] - 'a'];
                }
            }
        }
        return false;
    }

    bool search(string word, Node *node) {
        int len = word.length();
        Node *curNode = node;
        for (int i = 0; i < len; i++) {
            if (curNode->child[word[i] - 'a'] == NULL) return false;
            curNode = curNode->child[word[i] - 'a'];
        }
        return curNode->isend;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
