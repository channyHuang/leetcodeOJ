class MapSum {
public:
    class Node {
    public:
        char c;
        Node *children[256];
        bool isend;
        int val;
        Node (char _c = ' ') {
            c = _c;
            for (int i = 0; i < 256; i++) {
                children[i] = NULL;
            }
            isend = false;
            val = 0;
        }
    };
    Node *root;

    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        int len = key.length();
        Node *curNode = root;
        for (int i = 0; i < len; i++) {
            if (curNode->children[key[i]] == NULL) curNode->children[key[i]] = new Node(key[i]);
            curNode = curNode->children[key[i]];
        }
        curNode->isend = true;
        curNode->val = val;
    }
    
    int sum(string prefix) {
        int len = prefix.length();
        Node *curNode = root;
        for (int i = 0; i < len; i++) {
            if (curNode->children[prefix[i]] == NULL) return 0;
            curNode = curNode->children[prefix[i]];
        }
        return sum(curNode);
    }

    int sum(Node *node) {
        if (node == NULL) return 0;
        int res = 0;
        if (node->isend) res += node->val;
        for (int i = 0; i < 256; i++) {
            if (node->children[i] == NULL) continue;
            res += sum(node->children[i]);
        } 
        return res;
    } 
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
