class MyHashSet {
public:
    set<int> sets;
    /** Initialize your data structure here. */
    MyHashSet() {
        sets.clear();
    }
    
    void add(int key) {
        sets.insert(key);
    }
    
    void remove(int key) {
        sets.erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return (sets.find(key) != sets.end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
