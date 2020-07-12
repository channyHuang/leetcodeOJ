class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        count = capacity;
    }
    
    void push(int val) {
        if (unused.empty()) unused.insert(maps.size());
        setsitr = unused.begin();
        maps[*setsitr].push(val);
        
        if (maps[*setsitr].size() >= count) {
            unused.erase(setsitr);
        }
    }
    
    int pop() {
        if (maps.empty()) return -1;
        mapsitr = maps.end();
        mapsitr--;
        if (mapsitr->second.size() == count) unused.insert(mapsitr->first);
        int res = mapsitr->second.top();
        mapsitr->second.pop();       
        if (mapsitr->second.empty()) {            
            maps.erase(mapsitr);           
        }
        return res;
    }
    
    int popAtStack(int index) {
        mapsitr = maps.find(index);
        if (mapsitr == maps.end()) return -1;      
        if (mapsitr->second.size() == count) unused.insert(mapsitr->first);
        int res = mapsitr->second.top();
        mapsitr->second.pop();
        if (mapsitr->second.empty()) {
            maps.erase(mapsitr);           
        }
        return res;
    }
private:
    int count;
    set<int> unused;
    set<int>::iterator setsitr;
    map<int, stack<int>> maps;
    map<int, stack<int>>::iterator mapsitr;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
