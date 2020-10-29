class LFUCache {
public: 
    class Node {
    public:
        int key;
        int value;
        int time;
        int count;
        Node(int _key = 0, int _value = 0) {
            key = _key;
            value = _value;
            count = 1;
        }

        bool operator < (const Node& n) const {
            if (n.count == count) return time < n.time;
            return count < n.count;
        }
    };

    LFUCache(int capacity) {
        len = 0;
        maxn = capacity;
        minCnt = 0;
        curTime = 0;
    }

    void output() {
        return;
        cout << "---" << endl;
        for (set<Node>::iterator itr = sets.begin(); itr != sets.end(); itr++) {
            cout << (*itr).key << " " << (*itr).value << endl;
        }
    }
    
    int get(int key) {
        output();
        if (maxn == 0) return -1;

        curTime++;
        unordered_map<int, Node>::iterator itr = key2value.find(key);
        if (itr == key2value.end()) {
            return -1;
        }
        Node newnode = Node(key, itr->second.value);
        newnode.count = itr->second.count + 1;
        newnode.time = curTime;

        sets.erase(itr->second);
        key2value.erase(itr);
        
        key2value[key] = newnode;
        sets.insert(newnode);

        return newnode.value;
    }
    
    void put(int key, int value) {
        output();

        if (maxn == 0) return;

        unordered_map<int, Node>::iterator itr = key2value.find(key);
        if (itr != key2value.end()) {
            itr->second.value = value;
            get(key);
            return;
        }

        if (len >= maxn) {
            len--;
            set<Node>::iterator sitr = sets.begin();
            itr = key2value.find((*sitr).key);

            key2value.erase(itr);
            sets.erase(sitr);
        }

        curTime++;

        Node newNode = Node(key, value);
        newNode.time = curTime;
        key2value[key] = newNode;
        sets.insert(newNode);
        len++;
    }

private:
    unordered_map<int, Node> key2value;
    set<Node> sets;
    int len;
    int maxn;
    int curTime;
    int minCnt;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
