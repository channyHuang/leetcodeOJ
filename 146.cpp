class LRUCache {
public:
    LRUCache(int capacity) {
        maps.clear();
        keyValues.clear();
        maxCount = capacity;
        count = 0;
    }
    
    int get(int key) {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator itrMap = maps.find(key);
        if (itrMap == maps.end()) return -1;
        pair<int, int> curPair = *itrMap->second;
        if (count == 1) return curPair.second;
        keyValues.erase(itrMap->second);
        keyValues.push_front(pair<int, int>(key, curPair.second));
        maps.erase(itrMap);
        maps.insert(pair<int, list<pair<int, int>>::iterator>(key, keyValues.begin()));
        return curPair.second;
    }
    
    void put(int key, int value) {
        unordered_map<int, list<pair<int, int>>::iterator>::iterator itrMap = maps.find(key);
        if (itrMap != maps.end()) {
            keyValues.erase(itrMap->second);
            keyValues.push_front(pair<int, int>(key, value));
            maps[key] = keyValues.begin();
            return;
        }
        if (count >= maxCount) {
            pair<int, int> delValue = keyValues.back();
            itrMap = maps.find(delValue.first);
            if (itrMap != maps.end()) {
                maps.erase(itrMap);
                keyValues.pop_back();
                count--;
            }
        }
        keyValues.push_front(pair<int, int>(key, value));
        maps[key] = keyValues.begin();
        count++;
    }

private:
    unordered_map<int, list<pair<int, int>>::iterator> maps;
    list<pair<int, int>> keyValues;
    int maxCount;
    int count;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
