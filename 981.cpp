class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        maps.clear();
    }
    
    void set(string key, string value, int timestamp) {
        itr = maps.find(key);
        if (itr == maps.end()) {
            vector<pair<int, string>> sub;
            sub.push_back(pair<int, string>(timestamp, value));
            maps.insert(pair<string, vector<pair<int, string>>>(key, sub));
        } else {
            itr->second.push_back(pair<int, string>(timestamp, value));
        }
    }
    
    string get(string key, int timestamp) {
        itr = maps.find(key);
        if (itr == maps.end()) return "";
        string res = "";
        int stPos = 0, endPos = itr->second.size() - 1;
        while (stPos <= endPos) {
            int midPos = (stPos + endPos) / 2;
            if (itr->second[midPos].first <= timestamp) {
                res = itr->second[midPos].second;
                stPos = midPos + 1;
            } else endPos = midPos - 1;
        }
        return res;
    }

private:
    unordered_map<string, vector<pair<int, string>>> maps;
    unordered_map<string, vector<pair<int, string>>>::iterator itr;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
