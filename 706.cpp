class MyHashMap {
public:
    map<int, int> maps;
    map<int, int>::iterator itr;
    /** Initialize your data structure here. */
    MyHashMap() {
        maps.clear();
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        itr = maps.find(key);
        if (itr == maps.end()) maps.insert(make_pair(key, value));
        else itr->second = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        itr = maps.find(key);
        if (itr == maps.end()) return -1;
        return itr->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        maps.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
