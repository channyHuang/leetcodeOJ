class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        key_value.clear();
        value_key.clear();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        itr = key_value.find(key);
        if (itr == key_value.end()) {
            key_value[key] = 1;
            value_key[1].insert(key);
        } else {
            map<int, unordered_set<string>>::iterator vitr = value_key.find(itr->second);
            unordered_set<string>::iterator nitr = vitr->second.find(key);
            vitr->second.erase(nitr);
            if (vitr->second.empty()) {
                value_key.erase(vitr);
            }
            itr->second++;
            value_key[itr->second].insert(key);
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        itr = key_value.find(key);
        if (itr != key_value.end()) {
            map<int, unordered_set<string>>::iterator vitr = value_key.find(itr->second);
            unordered_set<string>::iterator nitr = vitr->second.find(key);
            vitr->second.erase(nitr);
            if (vitr->second.empty()) {
                value_key.erase(vitr);
            }
            itr->second--;
            if (itr->second == 0) {
                key_value.erase(itr);
            } else {
                value_key[itr->second].insert(key);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (value_key.empty()) {
            return "";
        }
        map<int, unordered_set<string>>::iterator nitr = value_key.end();
        nitr--;
        return *(nitr->second.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (value_key.empty()) {
            return "";
        }
        map<int, unordered_set<string>>::iterator nitr = value_key.begin();
        return *(nitr->second.begin());
    }

private:
    unordered_map<string, int> key_value;
    map<int, unordered_set<string>> value_key;
    unordered_map<string, int>::iterator itr;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
