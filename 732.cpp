class MyCalendarThree {
public:
    MyCalendarThree() {
        maps.clear();
        res = 0;
    }
    
    int book(int start, int end) {
        if (end <= start) return res;
        itr = maps.upper_bound(start);
        if (itr == maps.end() || itr->second.first >= end) {
            maps[end] = pair<int, int>(start, 1);
            res = max(res, 1);
            return res;
        } 
        if (start < itr->second.first) {
            maps[itr->second.first] = pair<int, int>(start, 1);
            res = max(res, 1);
            book(itr->second.first, end);
            return res;
        }
        if (start > itr->second.first) {
            maps[start] = pair<int, int>(itr->second.first, itr->second.second);
            itr->second.first = start;
            book(start, end);
            return res;
        }
        //start == itr->second
        if (itr->first > end) {
            maps[end] = pair<int, int>(itr->second.first, itr->second.second + 1);
            res = max(res, itr->second.second + 1);
            itr->second.first = end;
        } else {
            itr->second.second++;
            res = max(res, itr->second.second);
            book(itr->first, end);
        }
        //output();
        return res;
    }

    void output() {
        for (itr = maps.begin(); itr != maps.end(); itr++) {
            cout << itr->second.first << " " << itr->first << " " << itr->second.second << endl;
        }
    }

private:
    //pair<int, int> : left, count
    map<int, pair<int, int>> maps;
    map<int, pair<int, int>>::iterator itr;
    int res;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
