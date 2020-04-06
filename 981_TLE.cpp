class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        maps.clear();
    }
    
    void set(string key, string value, int timestamp) {
        itr = maps.find(key);
        if (itr == maps.end()) {
            map<int, string> sub;
            sub.insert(pair<int, string>(timestamp, value));
            maps.insert(pair<string, map<int, string>>(key, sub));
        } else {
            itr->second.insert(pair<int, string>(timestamp, value));
        }
    }
    
    string get(string key, int timestamp) {
        itr = maps.find(key);
        if (itr == maps.end()) return "";
        string res = "";
        for (map<int, string>::iterator tmpItr = itr->second.begin(); tmpItr != itr->second.end(); tmpItr++) {
            if (tmpItr->first <= timestamp) res = tmpItr->second;
            else break;
        }
        return res;
    }

private:
    unordered_map<string, map<int, string>> maps;
    unordered_map<string, map<int, string>>::iterator itr;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
