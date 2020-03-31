class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        count = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        unordered_map<int, int>::iterator itr = maps.find(val);
        if (itr == maps.end()) {
            if (vec.size() > count) vec[count] = val;
            else vec.push_back(val);
            maps.insert(pair<int, int>(val, count));
            count++;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_map<int, int>::iterator itr = maps.find(val);
        if (itr == maps.end()) return false;
        if (count > 1) {
            vec[itr->second] = vec[count - 1];
            maps[vec[count - 1]] = itr->second;
        }
        count--;
        maps.erase(itr);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % count;
        return vec[idx];
    }

private:
    unordered_map<int, int> maps;
    vector<int> vec;
    int count;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
