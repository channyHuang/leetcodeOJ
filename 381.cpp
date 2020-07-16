class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        sets.clear();
        count = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool notContain = (sets.find(val) == sets.end());
        sets.insert(val);
        count++;
        return notContain;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool contained = false;
        itr = sets.find(val);
        if (itr != sets.end()) {
            contained = true;
            sets.erase(itr);
            count--;
        }
        return contained;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int idx = random() % count;
        itr = sets.begin();
        while (idx) {
            itr++;
            idx--;
        }
        return *itr;
    }

private:
    unordered_multiset<int> sets;
    unordered_multiset<int>::iterator itr;
    int count;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
