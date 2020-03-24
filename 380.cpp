class RandomizedSet {
public:
    vector<int> nums;
    unorder_map<int, int> maps;

    /** Initialize your data structure here. */
    RandomizedSet() {
        nums.clear();
        maps.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (maps.count(val)) return false;
        nums.push_back(val);
        maps.insert(val, nums.size() - 1);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!maps.count(val)) return false;
        int idx = maps[val];
        nums[idx] = nums[nums.size() - 1];
        maps[nums[idx]] = idx;
        nums.remove(val);
        maps.remove(val);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % (nums.size() - 1)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
