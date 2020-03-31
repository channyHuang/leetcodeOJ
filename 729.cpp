class MyCalendar {
public:
    MyCalendar() {
        maps.clear();
    }
    
    bool book(int start, int end) {
        maps[start]++;
        maps[end]--;
        int sum = 0;
        for(map<int, int>::iterator itr = maps.begin(); itr != maps.end(); itr++) {
            sum += itr->second;
            if (sum >= 2) {
                maps[start]--;
                maps[end]++;
                return false;
            }
        }
        return true;
    }

private:
    map<int, int> maps;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
