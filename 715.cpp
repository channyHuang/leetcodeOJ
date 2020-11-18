class RangeModule {
public:
    RangeModule() {
        maps.clear();
    }
    
    void addRange(int left, int right) {
        //cout << "add " << left << " " << right << endl;
        if (right < left) return;
        itr = maps.lower_bound(left);
        if (itr == maps.end()) {
            maps[right] = left;
        } else if (itr->second > right) {
            maps[right] = left;
        } else {
            itr->second = min(itr->second, left);
            if (itr->first <= right) {
                int nleft = min(itr->second, left);
                maps.erase(itr);
                addRange(nleft, right); 
            }
        }
        //output();   
    }
    
    bool queryRange(int left, int right) {
        itr = maps.lower_bound(left);
        if (itr == maps.end()) {
            return false;
        }
        return (itr->second <= left && itr->first >= right);
    }
    
    void removeRange(int left, int right) {
        //cout << "remove " << left << " " << right << endl;
        if (right < left) return;
        itr = maps.upper_bound(left);
        if (itr == maps.end() || itr->second > right) {
            return;
        }
        if (itr->second < left) {
            maps[left] = itr->second;
            itr->second = left + 1;
            left = left + 1;
        }
        if (itr->first > right) {
            itr->second = right;
        } else {
            maps.erase(itr);
            removeRange(left, right);
        }
        //output();
    }

    void output() {
        cout << "start output" << endl;
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            cout << itr->second << " " << itr->first << endl;
        }
        cout << "end output" << endl;
    }

private:
    map<int, int> maps;
    map<int, int>::iterator itr;
    map<int, int>::iterator nitr;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
